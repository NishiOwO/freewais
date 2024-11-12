/*                               -*- Mode: C -*- 
 * $Basename: ftwtest.c $
 * $Revision: 1.8 $
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Tue May  6 09:50:57 1997
 * Language        : C
 * Update Count    : 2
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */


#include <stdio.h>
#include "cdialect.h"
#include <sys/stat.h>

extern int alphasort();

static int
checkfile(s,st,flag)
char *s;
struct stat *st;
int flag;
{
    printf("name=\"%s\" flag=0x%x\n",s,flag);
    return 0;
}

main(ac, av)
	int ac;
	char *av[];
{
	register int i;
	register int j;
	Direntry_t **list;

	if (ac != 2) {
		fprintf(stderr, "usage: %s dirname\n", av[0]);
		exit(1);
	}
	if (chdir(av[1]) < 0) {
		perror(av[1]);
		exit(1);
	}

	if ((i = ftw(".", checkfile, 10 )) < 0) {
		perror("Error walking directory");
		exit(1);
	}
	exit(0);
}

