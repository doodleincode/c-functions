#include <stdio.h>
#include <stdlib.h>
#include "../include/io_lib.h"
#include "../include/status_lib.h"

int main()
{
    char buff[10];
    Status status;
    
    while (strncmp(buff, "exit", 4) != 0) {
        printf("Input: ");
        io_fgets(&status, buff, sizeof(buff), stdin);
        
        if (status.code != STATUS_SUCCESS) {
            printf("Status (%d): %s\n", status.code, status.msg);
            break;
        }
        
        printf("Repeat: %s\n", buff);
    }
    
    return 0;
}

