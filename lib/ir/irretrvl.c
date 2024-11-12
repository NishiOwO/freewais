/*                               -*- Mode: C -*- 
 * $Basename: irretrvl.c $
 * $Revision: 1.6.1.4.1.3 $
 * Author          : Brewster Kahle
 * Created On      : 10/91
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 11:24:50 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef lint
static char *PRCSid = "$Id: irretrvl.c 1.6.1.4.1.3 Mon, 05 May 1997 11:54:27 +0200 pfeifer $";
#endif

/* retrieval part of the serial ir engine.  if you are using a different 
   storage system for the documents, replace this file.

   -brewster

 10/91 added .Z file support from mlm@cs.brown.edu (Moises Lejter)

 to do:
  handle .Z files at a lower level.

 */

#include "irretrvl.h"
#include "irfiles.h" /* for filename_table_ext */
#include "cdialect.h"
#include "futil.h"
#include <ctype.h>  /* for isspace */
#include "irext.h"
#include <sys/stat.h>

#ifdef Mach
#include <sys/inode.h>
#endif /* Mach */

#ifndef S_ISDIR
#define S_ISDIR(f_mode) ((f_mode & S_IFMT) == S_IFDIR)
#endif

/*----------------------------------------------------------------------*/


boolean
parseDocID(doc,filename,start_character,end_character,errorCode)
DocObj* doc;
char* filename;
long* start_character;
long* end_character;
long* errorCode;
{
  DocID* theDocID = NULL;
  char* local_id = NULL;
  char* token = NULL;
  long i;

  if((theDocID = docIDFromAny(doc->DocumentID)) == NULL) 
    return false;

  local_id = anyToString(GetLocalID(theDocID));
  
  freeDocID(theDocID);

  /* parse the doc id into start pos, end pos, and filename */
  /* first the start char */
  token = local_id;
  for (i = 0; local_id[i] != '\0' && isspace(local_id[i]) == false; i++)
    ;
  if (local_id[i] == '\0')
   { 
     waislog(WLOG_HIGH, WLOG_WARNING, 
	     "Attempt to retrieve data for bad doc-id: '%s'",local_id); 
     *errorCode = GDT_BadDocID;
     s_free(local_id);
     return(false);
   }
  local_id[i] = '\0';
  sscanf(token,"%ld",start_character);
  /* now the second char */
  token = local_id + i + 1;
  for (++i; local_id[i] != '\0' && isspace(local_id[i]) == false; i++)
   ;
  if (local_id[i] == '\0')
   { 
     waislog(WLOG_HIGH, WLOG_WARNING, 
	     "Attempt to retrieve data for bad doc-id: '%s'",local_id); 
     *errorCode = GDT_BadDocID;
     s_free(local_id);
     return(false);
   }
  local_id[i] = '\0';
  sscanf(token,"%ld",end_character);
  /* and finally the file name */
  strncpy(filename,local_id + i + 1,MAX_FILENAME_LEN);
  s_free(local_id);
  return(true);
}


/*----------------------------------------------------------------------*/

/* this checks to make sure that the filename is a file 
   within the database */

static boolean check_for_legitimate_file 
  _AP((char *filename, char* database_name, char* index_directory));

static boolean check_for_legitimate_file(filename, database_name, index_directory)
     char *filename;
     char *database_name;  /* full pathname of the database */
     char *index_directory;
{
  struct stat sbuf;

  /* the help file and catalog file (the .src and .cat files) must be
     special cased because it is not in the filename table */

  /* caching is done in filename_in_filename_file for repeated requests 
     for the same file, so it does not need to be repeated here. */

  if(NULL != strstr(filename, ".src")) /* let it pass */
    return(true);

  if(NULL != strstr(filename, ".cat")) /* let it pass */
    return(true);

  stat(filename, &sbuf);
  if(S_ISDIR(sbuf.st_mode)) {
    waislog(WLOG_HIGH, WLOG_WARNING, 
	    "File: '%s' is a directory, and cannot be retrieved.",
	    filename);
    return(false);
  }
  else {
    /* name of the file of the filetable for this db (eg  /bar/foo.fn).  confusing, no? */
    char filename_table_filename[MAX_FILE_NAME_LEN +1]; 
    
    pathname_directory(database_name, filename_table_filename);
    strncat(filename_table_filename, "/", MAX_FILE_NAME_LEN);
    strncat(filename_table_filename, 
	    database_file(pathname_name(database_name)), 
	    MAX_FILE_NAME_LEN);
    s_strncat(filename_table_filename, filename_table_ext, MAX_FILE_NAME_LEN,
	      MAX_FILE_NAME_LEN);
    if(!filename_in_filename_file(filename, NULL, NULL, filename_table_filename)){
      /* we lose.  this means either the db does not exist, or
	 the file is not in that db.  Log the bad news */
      if(index_directory == NULL)
	return true;
      else if (substrcmp(filename, index_directory))
	return true;
      waislog(WLOG_HIGH, WLOG_WARNING, 
	      "File: '%s' is not in DB '%s', and cannot be retrieved.",
	      filename, filename_table_filename);
      return(false);
    }
    else{			/* everything is peachy */
      return(true);
    }
  }
}
  

/*--New one--------------------------------------------------------------------*/

WAISDocumentText* getData(doc, errorCode, index_directory)
DocObj* doc;
long* errorCode;
char* index_directory;
/* it isn't text, so we can just grab data */
{
  FILE* file = NULL;
  char fileName[MAX_FILENAME_LEN + 1];
  char savedFileName[MAX_FILENAME_LEN + 1];
  char* dbname = NULL;
  WAISDocumentText* data = NULL;
  long start,end;		/* position of the document in the file */
  long startByte,endByte,bytes,bytesRead; /* part of the doc that we want */
  char* buffer = NULL;
  any* bufAny = NULL;
  DocID *docid;
  char *tmpFileName = NULL;
  
  
/* multitype extensions */
  long int j = 0L;
  Boolean multitypeFlag = false;
  
  *errorCode = GDT_NoError;

  /* we can only handle byte chunks here */
  if ((doc->ChunkCode == CT_byte) ||
      (doc->ChunkCode == CT_document)) {
    if (parseDocID(doc,fileName,&start,&end,errorCode) == false)
     {
       waislog(WLOG_HIGH, WLOG_WARNING, "can't parse DocID");
       *errorCode = GDT_MissingDocID;
       return(NULL);
     }
 
  
    docid = docIDFromAny(doc->DocumentID);
    dbname = anyToString(GetDatabase(docid));
    freeDocID(docid);
    
    

    if(true == check_for_legitimate_file(fileName, dbname, index_directory)){

      
/* multitype extensions */
/* here we have the multitype extensions - we save the fileName and probe for a 
   multi-type file
 */
         multitypeFlag = true;

         if ( strcmp(fileName+(strlen(fileName)-2), ".Z") == 0 ) {
         /* it's a .Z file.  First, remove the suffix or many things get confused. */
           fileName[(strlen(fileName)-2)] = 0;
         }
         strcpy(savedFileName,fileName);
         
         /* strip the current extension, but not the period */
         for ( j = strlen(fileName); j >= 0L; j-- ) {
            if (fileName[j] == '.') {
               fileName[j+1] = 0;
               break;
            }
         }
         
         /* append the passed type to the file name */
         /* need to cut the document type short - gopher seems to send back 
            document type information
         */
         for ( j = 0L; j <= strlen(doc->Type); j++) {
           if (isupper(doc->Type[j]) == false) {
             doc->Type[j] = 0;
             break;
            }
         }
         strcat(fileName,doc->Type);

      
         if (probe_file(fileName)) {
            file = s_fopen(fileName, "rb");
         }
         else if (probe_file_possibly_compressed(fileName)) {
           tmpFileName = s_fzcat(fileName);
           if (tmpFileName) {
 	     file = s_fopen(tmpFileName, "rb");
 	   }
         }

      }


/* here we try to open the legitimate file - we restore the savedFileName */
     if ( file == NULL ) {
     
         multitypeFlag = false;
         strcpy(fileName,savedFileName);
         
         if (probe_file(fileName)) {
            file = s_fopen(fileName, "rb");
         }
         else if (probe_file_possibly_compressed(fileName)) {
           tmpFileName = s_fzcat(fileName);
           if (tmpFileName) {
 	     file = s_fopen(tmpFileName, "rb");
 	   }
         }

      }
      
    

    /* file is still not there, pretty serious */
    if (file == NULL) { 
      waislog(WLOG_HIGH, WLOG_WARNING, 
	      "Attempt to retrieve data for missing file (DocID): %s",
	      fileName);
      *errorCode = GDT_MissingDocID;
      s_free(dbname);
      if ( tmpFileName ) {
 	  unlink(tmpFileName);
 	  s_free(tmpFileName);
      }
      return(NULL);
    }

    if (doc->ChunkCode == CT_byte) {
      startByte = doc->ChunkStart.Pos + start;
      endByte = doc->ChunkEnd.Pos + start;
    }
    else {
      startByte = start;
      endByte = end;
    }

    waislog(WLOG_LOW, WLOG_RETRIEVE,
	    "Retrieving file (DocID): %s %ld %ld, byte range: %d %d, type: %s, from database %s", 
	    fileName, start, end, startByte, endByte, doc->Type, dbname);

/* multitype extensions */
/* only perform this check if this is *NOT* a multitype file, ie there could be 
   more than one document in this file
*/
    if ((endByte > end) && (end != 0) && (multitypeFlag == false)) { 
      waislog(WLOG_HIGH, WLOG_WARNING, 
	      "retrieval beyond bounds of file (DocID): %s %ld %ld, byte range: %ld %ld, type: %s, from database %s",
	      fileName,start, end, startByte,endByte,doc->Type,dbname);
      *errorCode = GDT_BadRange;
      endByte = end;
      
      if ( startByte > end ) {
	s_free(dbname);
        if ( tmpFileName ) {
 	  unlink(tmpFileName);
 	  s_free(tmpFileName);
        }
	return(NULL);
      }
    }
   


   
    /* get the bytes */
    if (fseek(file,startByte,SEEK_SET) != 0)
      { 
	waislog(WLOG_HIGH, WLOG_WARNING, 
		"retrieval can't seek to %ld in file <%s>",startByte,
		fileName);
	*errorCode = GDT_BadRange;
	s_free(dbname);
        if ( tmpFileName ) {
 	  unlink(tmpFileName);
 	  s_free(tmpFileName);
        }
	return(NULL);
      }

    bytes = endByte - startByte; 
    buffer = (char*)s_malloc(bytes);
  
    bytesRead = fread((void*)buffer,(size_t)sizeof(char),bytes,file);
  
/* multitype extensions */
    if (bytesRead != bytes)
      { 
      waislog(WLOG_HIGH, WLOG_WARNING, 
	      "retrieval beyond bounds of file (DocID): %s %ld %ld, byte range: %ld %ld, type: %s, from database %s",
	      fileName,start, end, startByte,endByte,doc->Type,dbname);
	*errorCode = GDT_BadRange;
	if (bytesRead == 0) {
	  s_free(dbname);
          if ( tmpFileName ) {
 	    unlink(tmpFileName);
 	    s_free(tmpFileName);
          }
	  return(NULL);
	}
      }
  

    bufAny = makeAny(bytesRead,buffer);
  
    data = makeWAISDocumentText(duplicateAny(doc->DocumentID),0L,bufAny);
  
    /* close the files */
    s_fclose(file);
    s_free(dbname);

     if ( tmpFileName ) {
 	unlink(tmpFileName);
 	s_free(tmpFileName);
     }
     return(data);
  }
  else
    { 
      waislog(WLOG_HIGH, WLOG_WARNING, 
	      "search engine can only use whole documents or byte offsets for data lookup");
      *errorCode = GDT_UnsupportedChunkType;

      s_free(dbname);
      if ( tmpFileName ) {
 	 unlink(tmpFileName);
 	 s_free(tmpFileName);
       }
       return(NULL);
    }

}

/*----------------------------------------------------------------------*/

#define BUFSZ	(size_t)5000

WAISDocumentText* getDocumentText(doc, errorCode, index_directory)
DocObj* doc;
long* errorCode;
char* index_directory;
/* find the text for doc, get the sub part if any, finally construct and
   return a WAISDocumentText.  If it can not find the document 
   (or some other error) it returns NULL and sets errorCode.
 */
{
  WAISDocumentText* text = NULL;
  FILE* file = NULL;
  char* dbname = NULL;
  char* buffer = NULL;
  any* bufAny = NULL;
  char fileName[MAX_FILENAME_LEN + 1];
  char savedFileName[MAX_FILENAME_LEN + 1];
  long start_character;
  long end_character;
  register long i;
  long bytes,bytesRead;
  long startByte,endByte,byte,lines;
  DocID* theDocID = NULL;
  char *tmpFileName = NULL;

/* multitype extensions */
  long int j = 0L;
  Boolean multitypeFlag = false;

  
  *errorCode = GDT_NoError;

  /* we can only handle line chunks for now */
  if (doc->ChunkCode != CT_line)
   { 
     waislog(WLOG_HIGH, WLOG_WARNING, 
	     "search engine can only use line offsets for now.");
     *errorCode = GDT_UnsupportedChunkType;
     return(NULL);
   }

  if (parseDocID(doc,fileName,&start_character,&end_character,errorCode) == 
      false) {
    waislog(WLOG_HIGH, WLOG_ERROR,"Can't parse DocID");
    *errorCode = GDT_MissingDocID;
    return(NULL);
  }

  theDocID = docIDFromAny(doc->DocumentID);
  dbname = anyToString(GetDatabase(theDocID));
  freeDocID(theDocID);

  waislog(WLOG_LOW, WLOG_RETRIEVE,
	  "Retrieving file (DocID): %s, line range: %d %d, type: %s, from database %s", 
	  fileName, doc->ChunkStart.Pos, doc->ChunkEnd.Pos, doc->Type,
	  dbname);


  
    if(true == check_for_legitimate_file(fileName, dbname, index_directory)){
      
/* multitype extensions */
/* here we have the multitype extensions - we save the fileName and probe for a 
   multi-type file
 */
         multitypeFlag = true;

         if ( strcmp(fileName+(strlen(fileName)-2), ".Z") == 0 ) {
         /* it's a .Z file.  First, remove the suffix or many things get confused. */
           fileName[(strlen(fileName)-2)] = 0;
         }
         strcpy(savedFileName,fileName);
         
         /* strip the current extension, but not the period */
         for ( j = strlen(fileName); j >= 0L; j-- ) {
            if (fileName[j] == '.') {
               fileName[j+1] = 0;
               break;
            }
         }
         
         /* append the passed type to the file name */
         /* need to cut the document type short - gopher seems to send back 
            document type information
         */
         for ( j = 0L; j <= strlen(doc->Type); j++) {
           if (isupper(doc->Type[j]) == false) {
             doc->Type[j] = 0;
             break;
            }
         }
         strcat(fileName,doc->Type);

      
         if (probe_file(fileName)) {
            file = s_fopen(fileName, "rb");
         }
         else if (probe_file_possibly_compressed(fileName)) {
           tmpFileName = s_fzcat(fileName);
           if (tmpFileName) {
 	     file = s_fopen(tmpFileName, "rb");
 	   }
         }
      }


/* here we try to open the legitimate file - we restore the savedFileName */
     if ( file == NULL ) {
      
         multitypeFlag = false;
         strcpy(fileName,savedFileName);
                  
        if (probe_file(fileName)) {
            file = s_fopen(fileName, "rb");
         }
         else if (probe_file_possibly_compressed(fileName)) {
           tmpFileName = s_fzcat(fileName);
           if (tmpFileName) {
 	     file = s_fopen(tmpFileName, "rb");
 	   }
         }
      }
      
    
  
    /* file is still not there, pretty serious */
    if (file == NULL) { 
      waislog(WLOG_HIGH, WLOG_WARNING, 
	      "Attempt to retrieve data for missing file (DocID): %s",
	      fileName);
      *errorCode = GDT_MissingDocID;
      s_free(dbname);
      if ( tmpFileName ) {
 	 unlink(tmpFileName);
 	 s_free(tmpFileName);
       }
      return(NULL);
    }


  if(0 != fseek(file, start_character, SEEK_SET))
   { 
     waislog(WLOG_HIGH, WLOG_WARNING, 
	     " error on attempt to seek into file for file (DocID): %s", fileName);
     s_free(dbname);
     *errorCode = GDT_BadRange;
     if ( tmpFileName ) {
 	unlink(tmpFileName);
        s_free(tmpFileName);
      }
     return(NULL);
   }
  /* find the start byte */
  buffer = (char*)s_malloc(BUFSZ);
  lines = byte = 0;
  while (lines < doc->ChunkStart.Pos)
   { /* search a buffer full */
     bytesRead = fread(buffer,(size_t)sizeof(char),BUFSZ,file); 
     for (i = 0; i < bytesRead && lines < doc->ChunkStart.Pos; i++, byte++)
      { if (buffer[i] == '\n' || buffer[i] == '\r')
	  /* \r should not happen because we are reading the file in text 
	     mode */
          lines++;
      }
     if (bytesRead == 0) /* cheasy handling files that don't end with nl */
       lines++;
   } 
  startByte = byte;
   
  
  /* find the end byte */ /* this could be done while getting the bytes XXX */
  /* search starting form the start pos */  
  if (fseek(file,startByte + start_character,SEEK_SET) != 0) 
   { 
     waislog(WLOG_HIGH, WLOG_WARNING, 
	     "retrieval can't seek to %ld in file <%s>",
	     startByte,fileName);
     
     *errorCode = GDT_BadRange;
     s_free(dbname);
     if ( tmpFileName ) {
	 unlink(tmpFileName);
 	 s_free(tmpFileName);
     }
     return(NULL);
   }

  
  while (lines < doc->ChunkEnd.Pos) 
   { /* search a buffer full */
     bytesRead = fread(buffer,(size_t)sizeof(char),BUFSZ,file); 
     for (i = 0; i < bytesRead && lines < doc->ChunkEnd.Pos; i++, byte++)
      { if (buffer[i] == '\n' || buffer[i] == '\r')
	  /* \r should not happen, we are reading the file in text mode */
          lines++;
      }
     if (bytesRead == 0) /* cheasy handling of files that don't end with nl */
       lines++;
   } 
  endByte = byte;
   
  
/* multitype extensions */
/* only perform this check if this is *NOT* a multitype file, ie there could be 
   more than one document in this file
*/
   if ((endByte + start_character > end_character) && (end_character != 0) && (multitypeFlag == false)) { 
     waislog(WLOG_HIGH, WLOG_WARNING, 
	      "retrieval beyond bounds of file (DocID): %s %ld %ld, byte range: %ld %ld, line range: %d %d, type: %s, from database %s",
	      fileName,start_character,end_character,startByte + start_character,endByte + start_character, 
	      doc->ChunkStart.Pos, doc->ChunkEnd.Pos, doc->Type,dbname);

      *errorCode = GDT_BadRange;
      endByte = end_character - start_character;

      if ( startByte > end_character ) {
	s_free(dbname);
        if ( tmpFileName ) {
 	  unlink(tmpFileName);
 	  s_free(tmpFileName);
        }
	return(NULL);
      }
    }

  


  s_free(buffer);
     
  /* get the bytes */
  if (fseek(file,startByte + start_character,SEEK_SET) != 0)
   { 
     waislog(WLOG_HIGH, WLOG_WARNING, 
	     "retrieval can't seek to %ld in file <%s>",startByte,
	     fileName);
     
     *errorCode = GDT_BadRange;
     s_free(dbname);
     if ( tmpFileName ) {
	 unlink(tmpFileName);
 	 s_free(tmpFileName);
     }
     return(NULL);
   }
   
  bytes = endByte - startByte; 
  buffer = (char*)s_malloc(bytes);
  
  bytesRead = fread((void*)buffer,(size_t)sizeof(char),bytes,file);
  
  if (bytesRead != bytes)
  { 
  
/* multitype extensions */
/*     waislog(WLOG_HIGH, WLOG_WARNING, 
	     "retrieval error in file <%s>",fileName);
*/
     waislog(WLOG_HIGH, WLOG_WARNING, 
	      "retrieval beyond bounds of file (DocID): %s %ld %ld, byte range: %ld %ld, type: %s, from database %s",
	      fileName,start_character,end_character,startByte + start_character,endByte + start_character,
	      doc->ChunkStart.Pos, doc->ChunkEnd.Pos, doc->Type,dbname);
     
     *errorCode = GDT_BadRange;
     s_free(dbname);
     if ( tmpFileName ) {
	 unlink(tmpFileName);
 	 s_free(tmpFileName);
     }
     return(NULL);
   }
  
  bufAny = makeAny(bytesRead,buffer);
  
  text = makeWAISDocumentText(duplicateAny(doc->DocumentID),0L,bufAny);
  
  /* close the files */
  s_free(dbname);
  s_fclose(file);
  if ( tmpFileName ) {
     unlink(tmpFileName);
     s_free(tmpFileName);
  }

  return(text);
}


