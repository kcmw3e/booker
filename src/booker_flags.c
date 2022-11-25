#include "booker_flags.h"

flag_t match_flag(char c);
flag_t match_flag_long(const char* s);

flag_t str_to_flag(const char* str) {
    size_t len = strlen(str);
    if (len < 2) return FLAG_NOT_FLAG;
    if (str[0] != FLAGCHAR_IDENTIFIER) return FLAG_NOT_FLAG;
    if (len == 2) return match_flag(str[1]); // ignore first '-' char
    if (str[1] == FLAGCHAR_IDENTIFIER) return match_flag_long(str + 2); // +2 to ignore leading '--'
    return FLAG_NOT_FLAG;
}

bool is_str_flag(const char* str) {
    flag_t flag = str_to_flag(str);
    if (flag == FLAG_NOT_FLAG) return false;
    return true;
}

bool isflag(flag_t flag) {
    switch(flag) {
        case (FLAG_HELP):
        case (FLAG_OUTPUT_FILE):
        case (FLAG_OUTPUT_FORMAT):
        case (FLAG_OUTPUT_DECORATIONS):
            return true;
        default:
            break;
    }
    return false;
}

flag_t match_flag(char c) {
    switch (c) {
        case (FLAGCHAR_HELP):               return FLAG_HELP;
        case (FLAGCHAR_OUTPUT_FILE):        return FLAG_OUTPUT_FILE;
        case (FLAGCHAR_OUTPUT_FORMAT):      return FLAG_OUTPUT_FORMAT;
        case (FLAGCHAR_OUTPUT_DECORATIONS): return FLAG_OUTPUT_DECORATIONS;
        default:
            break;
    }
        return FLAG_NOT_SUPPORTED;
}

flag_t match_flag_long(const char* flag) {
    // flag should not include the leading '--'
    if (strcmp(flag, FLAGCHAR_LONG_HELP) == 0)               return FLAG_HELP;
    if (strcmp(flag, FLAGCHAR_LONG_OUTPUT_FILE) == 0)        return FLAG_OUTPUT_FILE;
    if (strcmp(flag, FLAGCHAR_LONG_OUTPUT_FORMAT) == 0)      return FLAG_OUTPUT_FORMAT;
    if (strcmp(flag, FLAGCHAR_LONG_OUTPUT_DECORATIONS) == 0) return FLAG_OUTPUT_DECORATIONS;
    return FLAG_NOT_SUPPORTED;
}
