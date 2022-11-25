#ifndef BOOKER_FLAGS_H
#define BOOKER_FLAGS_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define FLAGCHAR '-'

enum flag {
    FLAG_NOT_FLAG           =  -1,
    FLAG_NOT_SUPPORTED      = 0x00,
    FLAG_HELP               = 0x01,
    FLAG_OUTPUT_FILE        = 0x02,
    FLAG_OUTPUT_FORMAT      = 0x04,
    FLAG_OUTPUT_DECORATIONS = 0x08,
};
typedef enum flag flag_t;

enum flagchar {
    FLAGCHAR_IDENTIFIER         = '-',
    FLAGCHAR_HELP               = 'h',
    FLAGCHAR_OUTPUT_FILE        = 'o',
    FLAGCHAR_OUTPUT_FORMAT      = 'f',
    FLAGCHAR_OUTPUT_DECORATIONS = 'd',
};
typedef enum flagchar flagchar_t;

static const char FLAGCHAR_LONG_HELP[] = "help";
static const char FLAGCHAR_LONG_OUTPUT_FILE[] = "out";
static const char FLAGCHAR_LONG_OUTPUT_FORMAT[] = "format";
static const char FLAGCHAR_LONG_OUTPUT_DECORATIONS[] = "decorations";

flag_t str_to_flag(const char* str);
bool is_str_flag(const char* str);
bool isflag(flag_t flag);

#endif // BOOKER_FLAGS_H
