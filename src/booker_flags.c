#include "booker_flags.h"

static const char FLAGS[] = {
    'f',
    'o',
    'd',
};
static const size_t NFLAGS = sizeof(FLAGS)/sizeof(*FLAGS);

bool isflag(const char* arg) {
    // a flag has a single FLAGCHAR character (usually '-') and a single letter after it
    size_t len = strlen(arg);
    if (len != 2) return false;
    if (arg[0] != FLAGCHAR) return false;

    return true;
}

bool isflagsupported(char flag) {
    for (size_t i = 0; i < NFLAGS; i++) {
        if (flag == FLAGS[i]) return true;
    }

        return false;
}
