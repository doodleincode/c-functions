/**
 * String handling functions
 *
 * @author 	Daniel Hong
 * 
 * This program is licensed under the GNU GENERAL PUBLIC LICENSE Version 2.
 * A LICENSE file should have accompanied this program.
 */

#ifndef _DH_STYPE_H_
#define _DH_STYPE_H_

/**
 * This function will try to intelligently determine if a string is of a number type
 *
 * @param   const char *    The string to check
 * @return  int             Returns 1 on true, 0 on false
 */
int is_number(const char *);

#endif /* _DH_STYPE_H_ */

