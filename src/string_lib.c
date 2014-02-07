/**
 * String functions
 *
 * @author 	Daniel Hong
 * 
 * GNU GENERAL PUBLIC LICENSE Version 2. A LICENSE file should have
 * accompanied this library.
 */

#include "../include/string_lib.h"

const char *str_tolower(char *str)
{
    int i;
    
	for (i = 0; str[i]; i++) {
		str[i] = tolower(str[i]);
	}
	
	return str;
}
