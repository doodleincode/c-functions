/**
 * String handling functions
 *
 * @author     Daniel Hong
 * 
 * This program is licensed under the GNU GENERAL PUBLIC LICENSE Version 2.
 * A LICENSE file should have accompanied this program.
 */

int is_number(const char *str)
{
    int i = 0;
    int dot_count = 0;          // i.e. decimal point
    int dot_placement = 0;
    int first_char_is_zero = 0;
    
    // Nothing provided?? Return FALSE!
    if (str && str[0] == '\0') {
        return 0;
    }
    
    // If first char is a dash (negative number), we'll advance the index
    // to skip it in our loop below
    if (str[0] == '-') {
        i++;
    }
    
    // If first char (or second if first is a dash) is zero
    if ((int)str[i] == 48) {
        first_char_is_zero = i + 1; // Mark the placement of where the dot should be
    }
    
    for (; str[i]; i++) {
        // Ignore NULL and newlines
        if ((int)str[i] == 0 || (int)str[i] == 10) {
            continue;
        }
        
        // If char is not 0-9 or a decimal point, we can return false immediately
        // since numbers shouldn't contain anything but 0-9 and optional decimal point
        // NOTE: We are considering commas in numbers as invalid
        if (((int)str[i] < 48 || (int)str[i] > 57) && (int)str[i] != 46) {
            return 0;
        }
        
        // If decimal point
        if ((int)str[i] == 46) {
            // Keep track of the number of dots
            dot_count++;
            
            // Keep track of the index of the decimal point placement in the string
            // We'll use this index to make sure that the decimal point is in a valid location
            if (dot_placement == 0) {
                dot_placement = i;
            }
        }
    }
    
    // If more than one decimal point was in the string, it's not a number!
    if (dot_count > 1) {
        return 0;
    }
    
    // If the first char was a zero, then the char immediately following needs to be
    // a decimal point, if not it wasn't a valid number!
    if (first_char_is_zero && dot_placement != first_char_is_zero) {
        return 0;
    }
    
    return 1;
}

