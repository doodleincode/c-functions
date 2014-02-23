#include <stdio.h>
#include <stdlib.h>
#include "../include/stype.h"

int main()
{
    char buff[100];
    
    while (1) {
        if (fgets(buff, sizeof(buff), stdin) == NULL) {
            break;
        }
        
        if (is_number(buff)) {
            printf("number\n");
        }
        else {
            printf("not a number\n");
        }
    }
    
    return 0;
}

