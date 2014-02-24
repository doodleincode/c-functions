/**
 * I/O functions that build upon or enhance existing STDIO functions
 *
 * @author 	Daniel Hong
 *
 * This program is licensed under the GNU GENERAL PUBLIC LICENSE Version 2.
 * A LICENSE file should have accompanied this program.
 */

#ifndef _DH_IO_LIB_H_
#define _DH_IO_LIB_H_

#include "status_lib.h"
 
/**
 * Works like fgets() but also flushes the stdin buffer if it was larger
 * than the supplied buffer. If you need to keep the overflown stdin buffer,
 * then use fgets() instead.
 *
 * Reads characters from stream and stores them as a C string into str until 
 * (max_len-1) characters have been read or either a newline or EOF is reached, 
 * whichever happens first.
 *
 * @param	Status *    OUT     (Optional) A pointer to a Status structure. Pass NULL if not using.
 * @param   char *      OUT     Char pointer
 * @param   int         IN      Number of bytes to read in
 * @param   FILE        IN      Pointer to a file stream to read from
 * @return  char                On success, returns str. On error, returns NULL
 *                              and sets the STATUS structure, if on was provided.
 */
char *io_fgets(Status *, char *, int, FILE *);

/**
 * Read the entire contents of a file at the given file path
 *
 * @param	Status *		OUT     (Optional) A pointer to a Status structure. Use NULL if not using.
 * @param	const char *	IN      Path of file to open
 * @return	char *			        Returns a buffer of the entire contents of the given file.
 *							        Returns NULL on error.
 *							        CAUTION: Be sure to free the returned char * pointer
 *                                  when you're done with it !!
 */
char *io_read_file(Status *, const char *);

/**
 * Write a formatted string to the file at the given file path
 *
 * @param	Status *		OUT     (Optional) A pointer to a Status structure. Use NULL if not using.
 * @param   const char *    IN      Path of file to write to
 * @param   const char *    IN      File operation mode. View fopen() man page to see
 *                                  allowed modes.
 * @param   const char *    IN      String format to write
 * @param   ...             IN      Arg list
 * @return  int                     On success the total number of characters wriiten.
 *                                  On error, a negative number is returned.
 */
int io_write_file(Status *, const char *, const char *, const char *, ...);

#endif /* _DH_IO_LIB_H_ */

