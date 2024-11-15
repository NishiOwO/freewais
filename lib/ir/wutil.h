/*                               -*- Mode: C -*- 
 * $Basename: wutil.h $
 * $Revision: 1.4.1.1 $
 * Author          : M. Tracy Shen
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 10:36:19 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universitšt Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

/*
 * ABSTRACT:    wutil.h -- WAIS TOOLS header file
 */

#ifndef _H_WAIS_util_
#define _H_WAIS_util_

#include "cdialect.h"

#include "cutil.h"

#ifdef __cplusplus
/* declare these as C style functions */
extern "C"
	{
#endif /* def __cplusplus */

void twais_format_req_apdu _AP(( boolean use_template, char* apdu_buff, long* len));
void twais_dsply_rsp_apdu _AP(( char* rsp_buff, long rsp_len));
void twais_free_apdu _AP((char* apdu_buff));

long twais_format_init_apdu _AP(( boolean use_template, char* apdu_buff));
long twais_format_typ3_srch_apdu _AP(( boolean use_template, char* apdu_buff));
long twais_format_typ1_srch_apdu _AP(( boolean use_template, char* apdu_buff));

void twais_dsply_init_rsp_apdu _AP(( char* buffer));
void twais_dsply_init_apdu _AP(( char* buffer));
void twais_dsply_srch_rsp_apdu _AP(( char* buffer));
void twais_dsply_srch_apdu _AP(( char* buffer));

void twais_tmplt_init_apdu _AP((char* buff, long* buff_len));
void twais_tmplt_init_rsp_apdu _AP((char* buff, long* buff_len));
void twais_tmplt_typ1_srch_apdu _AP(( char* buff, long* buff_len));
void twais_tmplt_typ3_srch_rsp_apdu _AP(( char* buff, long* buff_len));

#endif

#ifdef __cplusplus
	}
#endif /* def __cplusplus */
