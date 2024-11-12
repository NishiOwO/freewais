/*                               -*- Mode: C -*- 
 * $Basename: stringtoany.c $
 * $Revision: 1.3.1.4.1.3 $
 * Author          : jonathan@think.com
 * Created On      : 92/02/16  18:23:52
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 10:24:16 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

main(argc,argv)
int argc;
char **argv;
{
  char c;
  printf("(:any :size %d :bytes #( ", strlen(argv[1]));
  while(c = *argv[1]++) printf("%d ", c);
  printf(") )\n");
  exit(0);
}
