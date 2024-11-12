/*                               -*- Mode: C -*- 
 * $Basename: stoplist.c $
 * $Revision: 1.4.1.5.1.3 $
 * Author          : Jonny Goldman, Brewster Kahle
 * Created On      : 92/02/12  13:50:01
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 10:59:51 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

/* this is a set of utilities for maintaining a stoplist
 * kind of a kludge.
 *
 * -brewster
 */

#ifndef lint
static char *PRCSid = "$Id: stoplist.c 1.4.1.5.1.3 Mon, 05 May 1997 11:54:27 +0200 pfeifer $";
#endif

#include "stoplist.h"
#include "cdialect.h"

boolean use_both_stoplist;

#ifdef AUTO_STOPWORDS /* tung, 2/95 */
/*boolean use_both_stoplist = true;*/
static char stoplist_filename[MAX_FILENAME_LEN+5];
#else
static char stoplist_filename[MAX_FILENAME_LEN];/* dgg */
#endif

long    stoplist_pointer = 0;
char   *stoplist[] = {
    "a",
    "about",
    "above",
    "according",
    "across",
    "actually",
    "adj",
    "after",
    "afterwards",
    "again",
    "against",
    "all",
    "almost",
    "alone",
    "along",
    "already",
    "also",
    "although",
    "always",
    "among",
    "amongst",
    "an",
    "and",
    "another",
    "any",
    "anyhow",
    "anyone",
    "anything",
    "anywhere",
    "are",
    "aren't",
    "around",
    "as",
    "at",
    "b",
    "be",
    "became",
    "because",
    "become",
    "becomes",
    "becoming",
    "been",
    "before",
    "beforehand",
    "begin",
    "beginning",
    "behind",
    "being",
    "below",
    "beside",
    "besides",
    "between",
    "beyond",
    "billion",
    "both",
    "but",
    "by",
    "c",
    "can",
    "can't",
    "cannot",
    "caption",
    "co",
    "co.",
    "could",
    "couldn't",
    "d",
    "did",
    "didn't",
    "do",
    "does",
    "doesn't",
    "don't",
    "down",
    "during",
    "e",
    "each",
    "eg",
    "eight",
    "eighty",
    "either",
    "else",
    "elsewhere",
    "end",
    "ending",
    "enough",
    "etc",
    "even",
    "ever",
    "every",
    "everyone",
    "everything",
    "everywhere",
    "except",
    "f",
    "few",
    "fifty",
    "first",
    "five",
    "for",
    "former",
    "formerly",
    "forty",
    "found", "",
    "four",
    "from",
    "further",
    "g",
    "h",
    "had",
    "has",
    "hasn't",
    "have",
    "haven't",
    "he",
    "he'd",
    "he'll",
    "he's",
    "hence",
    "her",
    "here",
    "here's",
    "hereafter",
    "hereby",
    "herein",
    "hereupon",
    "hers",
    "herself",
    "him",
    "himself",
    "his",
    "how",
    "however",
    "hundred",
    "i",
    "i'd",
    "i'll",
    "i'm",
    "i've",
    "ie",
    "if",
    "in",
    "inc.",
    "indeed",
    "instead",
    "into",
    "is",
    "isn't",
    "it",
    "it's",
    "its",
    "itself",
    "j",
    "k",
    "l",
    "last",
    "later",
    "latter",
    "latterly",
    "least",
    "less",
    "let",
    "let's",
    "like",
    "likely",
    "ltd",
    "m",
    "made",
    "make",
    "makes",
    "many",
    "maybe",
    "me",
    "meantime",
    "meanwhile",
    "might",
    "million",
    "miss",
    "more",
    "moreover",
    "most",
    "mostly",
    "mr",
    "mrs",
    "much",
    "must",
    "my",
    "myself",
    "n",
    "namely",
    "neither",
    "never",
    "nevertheless",
    "next",
    "nine",
    "ninety",
    "no",
    "nobody",
    "none",
    "nonetheless",
    "noone",
    "nor",
    "not",
    "nothing",
    "now",
    "nowhere",
    "o",
    "of",
    "off",
    "often",
    "on",
    "once",
    "one",
    "one's",
    "only",
    "onto",
    "or",
    "other",
    "others",
    "otherwise",
    "our",
    "ours",
    "ourselves",
    "out",
    "over",
    "overall",
    "own",
    "p",
    "per",
    "perhaps",
    "q",
    "r",
    "rather",
    "recent",
    "recently",
    "s",
    "same",
    "seem",
    "seemed",
    "seeming",
    "seems",
    "seven",
    "seventy",
    "several",
    "she",
    "she'd",
    "she'll",
    "she's",
    "should",
    "shouldn't",
    "since",
    "six",
    "sixty",
    "so",
    "some",
    "somehow",
    "someone",
    "something",
    "sometime",
    "sometimes",
    "somewhere",
    "still",
    "stop",
    "such",
    "t",
    "taking",
    "ten",
    "than",
    "that",
    "that'll",
    "that's",
    "that've",
    "the",
    "their",
    "them",
    "themselves",
    "then",
    "thence",
    "there",
    "there'd",
    "there'll",
    "there're",
    "there's",
    "there've",
    "thereafter",
    "thereby",
    "therefore",
    "therein",
    "thereupon",
    "these",
    "they",
    "they'd",
    "they'll",
    "they're",
    "they've",
    "thirty",
    "this",
    "those",
    "though",
    "thousand",
    "three",
    "through",
    "throughout",
    "thru",
    "thus",
    "to",
    "together",
    "too",
    "toward",
    "towards",
    "trillion",
    "twenty",
    "two",
    "u",
    "under",
    "unless",
    "unlike",
    "unlikely",
    "until",
    "up",
    "upon",
    "us",
    "used",
    "using",
    "v",
    "very",
    "via",
    "w",
    "was",
    "wasn't",
    "we",
    "we'd",
    "we'll",
    "we're",
    "we've",
    "well",
    "were",
    "weren't",
    "what",
    "what'll",
    "what's",
    "what've",
    "whatever",
    "when",
    "whence",
    "whenever",
    "where",
    "where's",
    "whereafter",
    "whereas",
    "whereby",
    "wherein",
    "whereupon",
    "wherever",
    "whether",
    "which",
    "while",
    "whither",
    "who",
    "who'd",
    "who'll",
    "who's",
    "whoever",
    "whole",
    "whom",
    "whomever",
    "whose",
    "why",
    "will",
    "with",
    "within",
    "without",
    "won't",
    "would",
    "wouldn't",
    "x",
    "y",
    "yes",
    "yet",
    "you",
    "you'd",
    "you'll",
    "you're",
    "you've",
    "your",
    "yours",
    "yourself",
    "yourselves",
    "z", NULL
};

long    nstops = 0;
long nstops_pointer = 0;
char  **stop_from_file = NULL;	/* dgg */
char  **stop_ptr = NULL;		/* dgg */
typedef char    (*charptr);

void stop_list_file (filename)
     char *filename;
{
    strcpy (stoplist_filename, filename);
#ifdef AUTO_STOPWORDS /* tung, 2/95 */
    strcat(stoplist_filename, STOP);
#endif
}

#ifdef AUTO_STOPWORDS /* tung, 2/95 */
void init_stop_list(database_file) 
     char* database_file;
#else
void init_stop_list();
#endif
{
/*
#ifdef BIO
*/
#ifdef AUTO_STOPWORDS /* tung, 2/95 */
  stop_list_file(database_file);
#endif

  if (nstops > 0 && stop_from_file != NULL) {/* dgg */
    int i;
    for (i = 0; i < nstops; i++)
      free (stop_from_file[i]);
    free (stop_from_file);
    nstops = 0;
  }
  /* printf("init_stop_list: stoplist file is '%s'\n", stoplist_filename); */
  if (stoplist_filename[0] != '\0') {
    char    word[256];
    FILE * fp;
    fp = fopen (stoplist_filename, "r");
#ifdef AUTO_STOPWORDS /* tung, 2/95 */
    if(fp != NULL) {
#else
    if(fp == NULL) {
      panic("stoplist '%s' missing!", stoplist_filename);
    }
#endif
    nstops = 1;
    stop_from_file = (char**)malloc (nstops * sizeof (charptr));
    while (fgets (word, 255, fp)) {
      char   *cp = strstr (word, "\n");
      if (cp != NULL)
	*cp = '\0';
      stop_from_file[nstops - 1] = (char*)malloc(strlen (word) + 1);
      strcpy (stop_from_file[nstops - 1], word);
      /* printf("init_stop_list: word %d is '%s'\n", nstops, stop_from_file[nstops-1]); */
      nstops++;
      stop_from_file = (char**)realloc(stop_from_file, nstops * sizeof (charptr));
    }
    fclose (fp);
    stop_from_file[nstops - 1] = NULL;
    /*stop_ptr = stop_from_file;*/
    /* printf("init_stop_list: read %d stop words from '%s'\n", nstops-1, stoplist_filename); */
  }
/*
  else
#endif
*/
#ifdef AUTO_STOPWORDS /* tung, 2/95 */
  }
#endif 

#ifdef AUTO_STOPWORDS /* tung, 2/95 */
  if(use_both_stoplist) 
#endif
    stop_ptr = stoplist;
  stoplist_pointer = 0;
  nstops_pointer = 0;
}


char   *next_stop_word () {

#ifdef AUTO_STOPWORDS /* tung, 2/95 */
  if((stop_from_file == NULL) && (stop_ptr == NULL)) {
    return(NULL);
  }
  if(stop_from_file != NULL) {
    if(stop_from_file[nstops_pointer] != NULL) {
      return(stop_from_file[nstops_pointer++]);
    }
  }
  if(stop_ptr != NULL) {
    if(stop_ptr[stoplist_pointer] != NULL) {
      return(stop_ptr[stoplist_pointer++]);
    }
  }
  return(NULL);
#else
  /* AA 9/2/94 -- use either the built in stop words
   * or the ones from external file, but not both */
  if(stop_from_file != NULL) {
    if(stop_from_file[nstops_pointer] == NULL) {
      return(NULL);
    }
    else
      return(stop_from_file[nstops_pointer++]);
  }
  else {
    if(stop_ptr[stoplist_pointer] == NULL)
      return(NULL);
    else
      return(stop_ptr[stoplist_pointer++]);
  }
  
  /* returns NULL if all out */
  if(stop_ptr[stoplist_pointer] == NULL) {
    if(stop_from_file != NULL) {
      if(stop_from_file[nstops_pointer] == NULL)
	return(NULL);
      else
	return(stop_from_file[nstops_pointer++]);
    }
    else return (NULL);
  }
  else
    return (stop_ptr[stoplist_pointer++]);
#endif
}

#ifdef AUTO_STOPWORDS /* tung, 2/95 */

void add_auto_stopword(stopword)
     char* stopword;
{
  FILE * fp = NULL;
  fp = fopen (stoplist_filename, "a+");
  if(fp == NULL) {
    panic("stoplist '%s' missing!", stoplist_filename);
  }
 /* fseek(fp, 0L, 2); */
  fprintf(fp, "%s", stopword);
  fputc('\n', fp);
  fclose(fp);
}
#endif
