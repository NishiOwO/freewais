/*                               -*- Mode: C -*- 
 * $Basename: wprot.h $
 * $Revision: 1.4.1.1.1.1 $
 * Author          : Harry Morris, morris@think.com
 * Created On      : 3.26.90
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 10:39:42 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universitšt Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef _H_WAIS_protocol_

#define _H_WAIS_protocol_

#include "cdialect.h"

#include "zprot.h"
#include "ztype1.h"

/*----------------------------------------------------------------------*/
/* Data types / constants */

/* date factor constants */
#ifndef DF_INDEPENDENT
#define	DF_INDEPENDENT		1
#define DF_LATER		2
#define DF_EARLIER		3
#define DF_SPECIFIED_RANGE	4
#endif

/* chunk types */
#define CT_document		0
#define CT_byte			1
#define CT_line			2
#define CT_paragraph	3

/* relevance feedback query */
#define QT_RelevanceFeedbackQuery	"3"
#define QT_TextRetrievalQuery		QT_BooleanQuery

/* new data tags */
#define DT_UserInformationLength	(data_tag)99
#define	DT_ChunkCode			(data_tag)100
#define	DT_ChunkIDLength		(data_tag)101
#define	DT_ChunkMarker			(data_tag)102
#define	DT_HighlightMarker		(data_tag)103
#define	DT_DeHighlightMarker		(data_tag)104
#define	DT_NewlineCharacters		(data_tag)105
#define	DT_SeedWords			(data_tag)106
#define	DT_DocumentIDChunk		(data_tag)107
#define	DT_ChunkStartID			(data_tag)108
#define	DT_ChunkEndID			(data_tag)109
#define	DT_TextList			(data_tag)110
#define	DT_DateFactor			(data_tag)111
#define	DT_BeginDateRange		(data_tag)112
#define	DT_EndDateRange			(data_tag)113
#define	DT_MaxDocumentsRetrieved	(data_tag)114
#define	DT_SeedWordsUsed		(data_tag)115
#define	DT_DocumentID			(data_tag)116
#define	DT_VersionNumber		(data_tag)117
#define	DT_Score			(data_tag)118
#define	DT_BestMatch			(data_tag)119
#define	DT_DocumentLength		(data_tag)120
#define	DT_Source			(data_tag)121
#define	DT_Date				(data_tag)122
#define	DT_Headline			(data_tag)123
#define	DT_OriginCity			(data_tag)124
#define	DT_PresentStartByte		(data_tag)125
#define	DT_TextLength			(data_tag)126
#define	DT_DocumentText			(data_tag)127
#define	DT_StockCodes			(data_tag)128
#define	DT_CompanyCodes			(data_tag)129
#define	DT_IndustryCodes		(data_tag)130

/* added by harry */
#define DT_DocumentHeaderGroup		(data_tag)150
#define DT_DocumentShortHeaderGroup	(data_tag)151
#define DT_DocumentLongHeaderGroup	(data_tag)152
#define DT_DocumentTextGroup		(data_tag)153
#define DT_DocumentHeadlineGroup 	(data_tag)154
#define DT_DocumentCodeGroup		(data_tag)155
#define DT_Lines					(data_tag)131 
#define	DT_TYPE_BLOCK				(data_tag)132
#define DT_TYPE						(data_tag)133

/* wais element sets */
#define ES_DocumentHeader		"Document Header"
#define ES_DocumentShortHeader	"Document Short Header"
#define ES_DocumentLongHeader	"Document Long Header"
#define ES_DocumentText			"Document Text"
#define ES_DocumentHeadline		"Document Headline"
#define ES_DocumentCodes		"Document Codes"

typedef struct DocObj { /* specifies a section of a document */
	any*	DocumentID;
	char*   Type;
	long	ChunkCode;
	union {
		long	Pos;
		any*	ID;
	} ChunkStart;
	union {
		long	Pos;
		any*	ID;
	} ChunkEnd;
	} DocObj;
	
/*----------------------------------------------------------------------*/
/* WAIS APDU extensions */

typedef struct WAISInitResponse {
	long				ChunkCode;
	long				ChunkIDLength;
	char*				ChunkMarker;
	char*				HighlightMarker;
	char* 				DeHighlightMarker;
	char*				NewlineCharacters;
	/* XXX  need to add UpdateFrequency and Update Time */
	} WAISInitResponse;

typedef struct WAISSearch {
	char*				SeedWords;
	DocObj**			Docs;
	char**				TextList;
	long				DateFactor;
	char*				BeginDateRange;
	char*				EndDateRange;
	long				MaxDocumentsRetrieved;
	} WAISSearch;

typedef struct WAISDocumentHeader {
	any*				DocumentID;
	long				VersionNumber;
	long				Score;     
	long				BestMatch; 
	long				DocumentLength;
	long 				Lines;
	char**				Types;
	char*				Source;
	char*				Date;
	char*				Headline;
	char*				OriginCity;
	} WAISDocumentHeader;

typedef struct WAISDocumentShortHeader {
	any*				DocumentID;
	long				VersionNumber;
	long				Score;     
	long				BestMatch; 
	long				DocumentLength;
	long 				Lines;
 	} WAISDocumentShortHeader;
 
typedef struct WAISDocumentLongHeader {
	any*				DocumentID;
	long				VersionNumber;
	long				Score;     
	long				BestMatch; 
	long				DocumentLength;
	long 				Lines;
	char**				Types;
	char*				Source;
	char*				Date;
	char*				Headline;
	char*				OriginCity;
	char*				StockCodes;
	char* 				CompanyCodes;
	char*				IndustryCodes;
 	} WAISDocumentLongHeader;

typedef struct WAISDocumentText {
	any*				DocumentID;
	long				VersionNumber;
	any*				DocumentText;
	} WAISDocumentText;
	
typedef struct WAISDocumentHeadlines {
	any*				DocumentID;
	long				VersionNumber;
	char*				Source;
	char*				Date;
	char*				Headline;
	char*				OriginCity;
	} WAISDocumentHeadlines;
	
typedef struct WAISDocumentCodes {
	any*				DocumentID;
	long				VersionNumber;
	char*				StockCodes;
	char*				CompanyCodes;
	char*				IndustryCodes;
	} WAISDocumentCodes;
	
typedef struct WAISSearchResponse {
	char*			       		SeedWordsUsed;
	WAISDocumentHeader** 		DocHeaders;
	WAISDocumentShortHeader** 	ShortHeaders;
	WAISDocumentLongHeader** 	LongHeaders;
	WAISDocumentText**			Text;
	WAISDocumentHeadlines**		Headlines;
	WAISDocumentCodes**			Codes;
	diagnosticRecord**			Diagnostics;
	} WAISSearchResponse;

/*----------------------------------------------------------------------*/
/* Functions */

#ifdef __cplusplus
/* declare these as C style functions */
extern "C"
	{
#endif /* def __cplusplus */

DocObj* makeDocObjUsingWholeDocument _AP((any* aDocID,char* type));
DocObj* makeDocObjUsingBytes _AP((any* aDocID,char* type,long start,long end));
DocObj* makeDocObjUsingLines _AP((any* aDocID,char* type,long start,long end));
DocObj* makeDocObjUsingParagraphs _AP((any* aDocID,char* type,any* start,any* end));
void freeDocObj _AP((DocObj* doc));

WAISInitResponse* makeWAISInitResponse _AP((long chunkCode,long chunkIDLen,
					    char* chunkMarker,char* highlightMarker,
					    char* deHighlightMarker,char* newLineChars));
void freeWAISInitResponse _AP((WAISInitResponse* init));

WAISSearch* makeWAISSearch _AP((
	char* seedWords,DocObj** docs,char** textList,
	long dateFactor,char* beginDateRange,char* endDateRange,
	long maxDocsRetrieved));
void freeWAISSearch _AP((WAISSearch* query));

WAISDocumentHeader* makeWAISDocumentHeader _AP((
	any* aDocID,long versionNumber,long score,long bestMatch,long docLen,
	long lines,char** types,char* source,char* date,char* headline,char* originCity));
void freeWAISDocumentHeader _AP((WAISDocumentHeader* header));
char* writeWAISDocumentHeader _AP((WAISDocumentHeader* header,char* buffer,long* len));
char* readWAISDocumentHeader _AP((WAISDocumentHeader** header,char* buffer));

WAISDocumentShortHeader* makeWAISDocumentShortHeader _AP((
	any* aDocID,long versionNumber,long score,long bestMatch,long docLen,long lines));
void freeWAISDocumentShortHeader _AP((WAISDocumentShortHeader* header));
char* writeWAISDocumentShortHeader _AP((WAISDocumentShortHeader* header,
                                   char* buffer,long* len));
char* readWAISDocumentShortHeader _AP((WAISDocumentShortHeader** header,char* buffer));

WAISDocumentLongHeader* makeWAISDocumentLongHeader _AP((
	any* aDocID,long versionNumber,long score,long bestMatch,long docLen,
	long lines,char** types,char* source,char* date, char* headline,char* originCity,
	char* stockCodes,char* companyCodes,char* industryCodes));
void freeWAISDocumentLongHeader _AP((WAISDocumentLongHeader* header));
char* writeWAISDocumentLongHeader _AP((WAISDocumentLongHeader* header,char* buffer,long* len));
char* readWAISDocumentLongHeader _AP((WAISDocumentLongHeader** header,char* buffer));

WAISSearchResponse* makeWAISSearchResponse _AP((
	char* seedWordsUsed,WAISDocumentHeader** docHeaders,
	WAISDocumentShortHeader** shortHeaders,
	WAISDocumentLongHeader** longHeaders,
	WAISDocumentText** text,WAISDocumentHeadlines** headlines,
	WAISDocumentCodes** codes,
	diagnosticRecord** diagnostics));
void freeWAISSearchResponse _AP((WAISSearchResponse* response));

WAISDocumentText* makeWAISDocumentText _AP((any* aDocID,long versionNumber,
				       any* documentText));
void freeWAISDocumentText _AP((WAISDocumentText* docText));
char* writeWAISDocumentText _AP((WAISDocumentText* docText,char* buffer,long* len));
char* readWAISDocumentText _AP((WAISDocumentText** docText,char* buffer));

WAISDocumentHeadlines* makeWAISDocumentHeadlines _AP((
	any* aDocID,long versionNumber,char* source,char* date,char* headline,
	char* originCity));
void freeWAISDocumentHeadlines _AP((WAISDocumentHeadlines* docHeadline));
char* writeWAISDocumentHeadlines _AP((WAISDocumentHeadlines* docHeadline,char* buffer,long* len));
char* readWAISDocumentHeadlines _AP((WAISDocumentHeadlines** docHeadline,char* buffer));

WAISDocumentCodes* makeWAISDocumentCodes _AP((
	any* aDocID,long versionNumber,char* stockCodes,char* companyCodes,
	char* industryCodes));
void freeWAISDocumentCodes _AP((WAISDocumentCodes* docCodes));
char* writeWAISDocumentCodes _AP((WAISDocumentCodes* docCodes,char* buffer,long* len));
char* readWAISDocumentCodes _AP((WAISDocumentCodes** docCodes,char* buffer));

any* makeWAISTextQuery _AP((DocObj** docs));
DocObj** readWAISTextQuery _AP((any* terms));

void CSTFreeWAISInitResponse _AP((WAISInitResponse* init));
void CSTFreeWAISSearch _AP((WAISSearch* query));
void CSTFreeDocObj _AP((DocObj* doc));
void CSTFreeWAISDocumentHeader _AP((WAISDocumentHeader* header));
void CSTFreeWAISDocumentShortHeader _AP((WAISDocumentShortHeader* header));
void CSTFreeWAISDocumentLongHeader _AP((WAISDocumentLongHeader* header));
void CSTFreeWAISSearchResponse _AP((WAISSearchResponse* response));
void CSTFreeWAISDocumentText _AP((WAISDocumentText* docText));
void CSTFreeWAISDocumentHeadlines _AP((WAISDocumentHeadlines* docHeadline));
void CSTFreeWAISDocumentCodes _AP((WAISDocumentCodes* docCodes));
void CSTFreeWAISTextQuery _AP(( any* query));

#ifdef __cplusplus
	}
#endif /* def __cplusplus */

/*----------------------------------------------------------------------*/

#endif /* ndef _H_WAIS_protocol_ */
