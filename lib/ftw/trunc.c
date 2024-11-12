/*                               -*- Mode: C -*- 
 * $Basename: trunc.c $
 * $Revision: 1.3.1.2 $
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 10:24:40 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#include <stdio.h>

main(argc, argv)
int argc;
char **argv;
{
  int len, i, c;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s length\n", argv[0]);
    exit(-1);
  }

  len = atoi(argv[1]);
  i = 0;
  while (EOF != (c = getchar())) {
    if (c == '\n') {
      putchar(c);
      fflush(stdout);
      i = 0;
    }
    else if (i++ < len)
      putchar(c);
  }
}
