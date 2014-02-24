/**
 * I/O functions that build upon or enhance existing STDIO functions
 *
 * @author     Daniel Hong
 * 
 * This program is licensed under the GNU GENERAL PUBLIC LICENSE Version 2.
 * A LICENSE file should have accompanied this program.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "../include/status_lib.h"
#include "../include/io_lib.h"

char *io_fgets(Status *status, char *str, int max_len, FILE *stream)
{
    if (str == NULL) {
        status_set(status, STATUS_NULL_POINTER, "NULL pointer exception.");
        return NULL;
    }
    
    int c, i = 0;
    
    // Read one character at a time from the stream. The loop will exit on any one 
    // of the following conditions:
    // 1) (max_len - 1) characters reached
    // 2) newline was encountered
    // 3) end-of-file stream was reached
    do {
        c = getc(stream);
        str[i++] = c;
    } while (i < (max_len - 1) && c != '\n' && c != EOF);
    
    // If getc() returned EOF, we'll check the error indicator to see if it was
    // because of an error
    if (feof(stream) && ferror(stream)) {
        status_set(status, STATUS_STREAM_READ_ERR, "Error reading from the file stream.");
        return NULL;
    }
    
    // Add null terminator at the end of the characters
    str[i] = '\0';
    
    // If the last character read in was not a newline, that means there are 
    // still stuff left in the stdin buffer.
    // We will flush it out here
    if (c != '\n' && c != EOF) {
        while (getc(stream) != '\n');
    }
    
    status_set(status, STATUS_SUCCESS, "");
    return str;
}

char *io_read_file(Status *status, const char *file)
{
    long buffer_size;
    size_t read_size;
    FILE *fd;
    
    if ((fd = fopen(file, "r")) == NULL) {
        status_set(status, STATUS_FILE_OPEN_ERR, "Error opening the file.");
        return NULL;
    }
    
    // Go to the end of the file
    if (fseek(fd, 0L, SEEK_END) != 0) {
        status_set(status, STATUS_FILE_SEEK_ERR, "Error seeking to the end of the file stream.");
        fclose(fd);
        return NULL;
    }
    
    // Get the size of the file
    if ((buffer_size = ftell(fd)) == -1) {
        status_set(status, STATUS_FILE_TELL_ERR, "Error getting position of the file stream.");
        fclose(fd);
        return NULL;
    }
    
    // Now we have to go back to the beginning of the file
    if (fseek(fd, 0L, SEEK_SET) != 0) {
        status_set(status, STATUS_FILE_SEEK_ERR, "Error seeking to the start of the file stream.");
        fclose(fd);
        return NULL;
    }
    
    // Allocate our buffer
    char *buffer = (char *)malloc(sizeof(char) * (buffer_size + 1));
    
    // Read in the entire file
    read_size = fread(buffer, sizeof(char), buffer_size, fd);
    
    // If the actual read size was different than the calculated file size,
    // some went wrong: either error or an EOF was prematurely reached
    if (read_size != buffer_size) {
        status_set(status, STATUS_FILE_READ_ERR, "Error reading the file.");
        fclose(fd);
        free(buffer);
        return NULL;
    }
    
    buffer[++read_size] = '\0';
    fclose(fd);
    
    status_set(status, STATUS_SUCCESS, "");
    return buffer;
}

int io_write_file(Status *status, const char *file, const char *mode, const char *format, ...)
{
    FILE *fd;
    status_set(status, STATUS_SUCCESS, "");
    
    if ((fd = fopen(file, mode)) == NULL) {
        status_set(status, STATUS_FILE_OPEN_ERR, "Error opening the file.");
        return -1;
    }
    
    int retval = 0;
    va_list args;
    va_start(args, format);
    retval = vfprintf(fd, format, args);
    
    if (ferror(fd)) {
        status_set(status, STATUS_VFPRINTF_ERR, "Error formatting the string.");
        retval = -2;
    }
    
    va_end(args);
    close(fd);
    return retval;
}

