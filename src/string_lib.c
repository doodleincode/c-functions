/**
 * String functions
 *
 * @author 	Daniel Hong
 * 
 * This program is licensed under the GNU GENERAL PUBLIC LICENSE Version 2.
 * A LICENSE file should have accompanied this program.
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
