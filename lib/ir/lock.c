/*                               -*- Mode: C -*- 
 * $Basename: lock.c $
 * $Revision: 1.3.1.5.1.3 $
 * Author          : M. Tracy Shen, Gordon Linoff
 * Created On      : 92/04/28  17:05:23
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 11:14:48 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef lint
static char *PRCSid = "$Id: lock.c 1.3.1.5.1.3 Mon, 05 May 1997 11:54:27 +0200 pfeifer $";
#endif

/*

	COPYRIGHT	1992 Thinking Machines Corporation
	AUTHOR		M. Tracy Shen
                        Modified version of Gordon Linoff's lock.c
	MODULE		lock.c -- handle lock files all in one place
	INTERFACES
            utlk_using_lock()   - check the existence of a lock file
            utlk_set_lock()     - set a lock file if one doesn't exist
            utlk_unset_lock()   - unset a lock file if one exists
	INTERNAL ROUTINES
	COMMENTS
*/

#include "cdialect.h"
#include <stdio.h> 
#include <sys/param.h>
#include <errno.h>		/* errno, EWOULDBLOCK, etc. */

#ifdef Mach
extern int errno;
#endif

#define SIGNOP 0		/* for using kill() to check if process is
				   alive */ 

#define FALSE 0
#define TRUE  1


#define LOCK_STORAGE_MODULE
#include "lock.h"
#undef LOCK_STORSGE_MODULE

#ifndef MAXPATHLEN
# define MAXPATHLEN 1024
#endif

/******************************************************************************
 *
 *	Function Name:	utlk_using_lock_and_get_pid
 *
 *
 *	Purpose:	check if update or query server is running
 *
 *	Returns:	return TRUE if process running, FALSE if not running
 *			NOT_RUNNING.
 *                      If pid is not NULL, sets it to the process id of
 *                      locking process.
 *
 *	Algorithm:	Find a lock file in /tmp for update or query, read
 *			pid from file, be sure process is running with that
 *			pid.
 *	End Algorithm
 */

long
    utlk_using_lock_and_get_pid (dbname, lock_type,pid_ptr)
char *dbname;
long    lock_type;
unsigned *pid_ptr;
{
    /* local variables */
    char lockfile_name[MAXPATHLEN];	/* absolute pathname of update lock */
    FILE *file_ptr;			/* for opening lock files */
    long pid;				/* pid of SC or update process */
    long status;

    if (! IN_LOCK_RANGE(lock_type)) {
	/* Out of range locks should never happen, but just in case . . . */
	return(FALSE);
        }

    sprintf( lockfile_name, "%s%s",dbname, lock_names[lock_type]);

    file_ptr = fopen(lockfile_name, "r"); /* look for an existing lock file */

    if (file_ptr == NULL) { 	/* didn't find lock file! */
	return(FALSE);
       }

    /* read pid from the lock file */
    status = fscanf(file_ptr, "%d", &pid);
    fclose(file_ptr);
    if (status == 0) {  /* is an empty lock file */
	return(FALSE);
        }

    /* Try a dummy kill; if ESRCH, process is not found.  Otherwise, assume
     * it's there. */
    status = kill(pid, SIGNOP);
    if ((status != 0) && (errno == ESRCH)) {
	return(FALSE);
    }
    if (pid_ptr != NULL) *pid_ptr = pid;
    return(TRUE);

    }  /* end utlk_using_lock_and_get_pid */

/******************************************************************************
 *
 *	Function Name:	utlk_using_lock
 *
 *
 *	Purpose:	check if update or query server is running
 *
 *	Returns:	return TRUE if process running, FALSE if not running
 *			NOT_RUNNING.
 *
 *	Algorithm:	Find a lock file in /tmp for update or query, read
 *			pid from file, be sure process is running with that
 *			pid.
 *	End Algorithm
 */

long
    utlk_using_lock (dbname, lock_type)
char *dbname;
long lock_type;
{
    return(utlk_using_lock_and_get_pid(dbname, lock_type, NULL));
}  /* end utlk_using_lock */



/******************************************************************************
 *
 *	Function Name:	utlk_unset_lock
 *
 *
 *	Purpose:	free lock
 *
 *	Returns:	Return TRUE is successful, FALSE if lock cannot be unset
 *
 *	Algorithm:	
 *	End Algorithm
 */

long
    utlk_unset_lock (dbname, lock_type)
char *dbname;
long lock_type;
{
    /* local variables */
    char lockfile_name[MAXPATHLEN];	/* absolute pathname of update lock */
    
    /* begin executable unset_lock */
    
    if (! IN_LOCK_RANGE(lock_type)) {
	/* Out of range locks should never happen, but just in case . . . */
	return(TRUE);
    }
    
    sprintf( lockfile_name, "%s%s",dbname, lock_names[lock_type]);
    
    return(unlink(lockfile_name) == 0);
}  /* end utlk_unset_lock */



/******************************************************************************
 *
 *	Function Name:	utlk_set_lock_with_pid
 *
 *
 *	Purpose:	set lock, process id is argument
 *
 *	Returns:	Return TRUE is successful, FALSE if lock cannot be set
 *
 *	Algorithm:	
 *	End Algorithm
 */

long
    utlk_set_lock_with_pid (dbname, lock_type, pid)
char *dbname;
long lock_type;			/* LOCK_UPDATE, etc. */
long pid;			/* pid of SC or update process */
{
    /* local variables */
    char lockfile_name[MAXPATHLEN];	/* absolute pathname of update lock */
    FILE *file_ptr;			/* for opening lock files */

    /* begin executable set_lock */
    
    if (! IN_LOCK_RANGE(lock_type)) {
	/* Out of range locks should never happen, but just in case . . . */
	return(FALSE);
	}
    
    sprintf( lockfile_name, "%s%s",dbname, lock_names[lock_type]);

    /* Don't look for an existing file -- just write over it */
    file_ptr = fopen(lockfile_name, "w");
    if (file_ptr == NULL) {	/* no write permission to db  */
	return(FALSE);
    }
    fprintf(file_ptr, "%d", pid);
    fclose(file_ptr);
    return(TRUE);
}  /* end utlk_set_lock */


/******************************************************************************
 *
 *	Function Name:	utlk_set_lock
 *
 *
 *	Purpose:	set lock
 *
 *	Returns:	Return TRUE is successful, FALSE if lock cannot be set
 *
 *	Algorithm:	
 *	End Algorithm
 */

long
    utlk_set_lock (dbname, lock_type)
char *dbname;
long lock_type;
{
    return(utlk_set_lock_with_pid(dbname, lock_type, getpid()));
}  /* end utlk_set_lock */
