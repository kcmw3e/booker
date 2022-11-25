#include "booker.h"
#include "booker_flags.h"
#include "booker_messages.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include <cuti.h>

// flags
// file options
// booker file.bok file.cov -o filename.txt -f plain -d none
// ^prog   ||           ||  |  |            ^format^ ^decorations^
//         ^^input files^^  |  ^output file
//                          ^output flag


int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("Error: no input file provided.\n");
        return EXIT_FAILURE;
    }

    cli_argwalk_t argwalk;
    for (argwalk = cli_argwalk_begin(argc, (const char**) argv, NULL); !cli_argwalk_done(argwalk); argwalk = cli_argwalk_next(argwalk)) {
        printf("Arg is %s\n", argwalk.arg.str);
    }

    if (is_cli_argwalk_errored(argwalk)) {
        printf("%s\n", argwalk.arg.str);
    }

    return EXIT_SUCCESS;
}
