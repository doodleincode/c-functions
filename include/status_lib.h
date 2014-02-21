/**
 * A status code implementation
 *
 * @author 	Daniel Hong
 *
 * This program is licensed under the GNU GENERAL PUBLIC LICENSE Version 2.
 * A LICENSE file should have accompanied this program.
 */

#ifndef _DH_STATUS_LIB_H_
#define _DH_STATUS_LIB_H_

// Status return codes
#define STATUS_SUCCESS					1
#define STATUS_ERROR					-1
#define STATUS_NULL_POINTER             -10
#define STATUS_OUT_OF_BOUNDS            -11

#define STATUS_STDIN_READ_ERR			-40
#define STATUS_FILE_OPEN_ERR			-41
#define STATUS_FILE_READ_ERR			-42
#define STATUS_FILE_SEEK_ERR			-43
#define STATUS_FILE_TELL_ERR			-44
#define STATUS_STREAM_READ_ERR          -45
#define STATUS_VFPRINTF_ERR             -46

#define STATUS_MSG_FORMAT_ERR           -60

#define STATUS_INVALID_INPUT			-100
#define STATUS_VALIDATION_RANGE_NOT_SET	-101

typedef struct {
    int code;
    const char *msg;
} Status;

void status_set(Status *, int, const char *);

void status_format_msg(Status *, int, const char *, ...);

#endif /* _DH_STATUS_LIB_H_ */

