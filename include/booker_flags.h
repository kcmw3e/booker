#ifndef BOOKER_FLAGS_H
#define BOOKER_FLAGS_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define FLAGCHAR '-'

bool isflag(const char* arg);
bool isflagsupported(char flag);

#endif // BOOKER_FLAGS_H
