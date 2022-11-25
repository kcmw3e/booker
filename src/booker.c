#include "booker.h"
#include "booker_flags.h"
#include "booker_messages.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// flags
// file options
// booker file.bok file.cov -o filename.txt -f plain -d none
// ^prog   ||           ||  |  |            ^format^ ^decorations^
//         ^^input files^^  |  ^output file
//                          ^output flag
//
// usage
//  booker [file1 file2 ...] [-o [file] -f [format] -d [dec1 dec2 ...]]
// options
//  -f [format]
//      format of the output, possible options:
//          * plain: for pain text
//          * pdf: for pdf output
//          * dvi: for dvi output (hopefully)
//          * mkd: for markdown output (likely)
//          * tex: for TEX otput (maybe)
//          * odt: open document (hopefully)
//          * doc: ms word (hopefully)
//      default is plain (for now)
//  -o [file]
//      output file
//      if -f flag is not specified, file extion will be used to
//          guess the format
//      if the file extension does not match a format, exit with error
//      if -f flag is specified, that format will be used and the output
//          file will still have the mismatched extension
//      default output file name is guessed from the format/default format
//          and the first input filename
//  -d [decoration decoration ...]
//      add decorations to the output (mainly used for pnain text and markdown)
//      possible options:
//          * none
//          * all
//          * page borders
//          * header
//          * footer
//      default is all

// a struct to organize/keep track of the options specified
struct args {
    // holds all the flag options specified when calling, and any defaults that need filling in
    int flags;

    // some flags can have more than one argument, so array of array of strings
    char*** flag_args;

    // the file names to parse
    char** filenames;
};

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("Error: no input file provided.\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < argc; i++) {
        const char* arg = (const char*)(argv[i]);
        bool flag = isflag(arg);
        bool sup;
        if (flag) sup = isflagsupported(arg[1]);
        if (arg[1] == 'h') fwrite(booker_usage, sizeof(*booker_usage), booker_usage_len, stdout);
        printf("[%s] %d: %s\n", flag ? (sup ? "\033[0;31mflag\033[0;37m" : "----") : "\033[0;32mfile\033[0;37m", i, argv[i]);
    }

    return EXIT_SUCCESS;
}
