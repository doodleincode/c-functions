#include <stdio.h>
#include <stdlib.h>
#include "../include/status_lib.h"
#include "../include/io_lib.h"

int main()
{
    Status status;
    
    
    io_write_file(&status, "iotest.txt", "a", "This is a non-formatted string!\n");
    io_write_file(&status, "iotest.txt", "a", "This is a formatted string! %d\n", 123);
    io_write_file(&status, "iotest.txt", "a", "This is a formatted string! %d\n", 123456);
    
    return 0;
}
