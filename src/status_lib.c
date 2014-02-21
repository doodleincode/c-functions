/**
 * A status code implementation
 *
 * @author 	Daniel Hong
 * 
 * This program is licensed under the GNU GENERAL PUBLIC LICENSE Version 2.
 * A LICENSE file should have accompanied this program.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "../include/status_lib.h"

void status_set(Status *status, int code, const char *msg)
{
    // Make sure pointer is not null
    if (status) {
        status->code = code;
        status->msg = msg;
    }
}

void status_format_msg(Status *status, int code, const char *format, ...)
{
    // Make sure the status pointer is not null
    if (status) {
        int chars_written = 0;
        char buffer[256];
        va_list args;
        
        va_start(args, format);
        chars_written = vsnprintf(buffer, sizeof(buffer), format, args);
        va_end(args);
        
        status->code = code;
        
        // Success!
        if (chars_written > 0 && chars_written < sizeof(buffer)) {
            // TODO: Hackish... requires a better way
            status->msg = malloc(strlen(buffer) + 1);
	        strncpy((char *)status->msg, buffer, strlen(buffer));
        }
        else {
            // If there was an error, we'll just set the status
            status->code = STATUS_MSG_FORMAT_ERR;
            status->msg = "Error formatting the status message.";
        }
    }
}

