#include "booker_options.h"

ofmt_t str_to_ofmt(const char* str) {
    if (str == NULL) return OFMT_NOT_SUPPORTED;

    if (strcmp(str, OFMT_STR_PLAIN) == 0) return OFMT_PLAIN;
    if (strcmp(str, OFMT_STR_PDF) == 0) return OFMT_PDF;
    if (strcmp(str, OFMT_STR_MARKDOWN) == 0) return OFMT_MARKDOWN;
    if (strcmp(str, OFMT_STR_TEX) == 0) return OFMT_TEX;
    if (strcmp(str, OFMT_STR_ODT) == 0) return OFMT_ODT;
    if (strcmp(str, OFMT_STR_DOC) == 0) return OFMT_DOC;

    return OFMT_NOT_SUPPORTED;
}

deco_t str_to_deco(const char* str) {
    if (str == NULL) return DECO_NOT_SUPPORTED;

    if (strcmp(str, DECO_STR_NONE) == 0) return DECO_NONE;
    if (strcmp(str, DECO_STR_ALL) == 0) return DECO_ALL;
    if (strcmp(str, DECO_STR_PAGE_BORDERS) == 0) return DECO_PAGE_BORDERS;
    if (strcmp(str, DECO_STR_HEADER) == 0) return DECO_HEADER;
    if (strcmp(str, DECO_STR_FOOTER) == 0) return DECO_FOOTER;

    return DECO_NOT_SUPPORTED;
}

bool is_str_ofmt(const char* str) {
    if (str == NULL) return false;

    ofmt_t ofmt = str_to_ofmt(str);
    if (ofmt == OFMT_NOT_SUPPORTED) return false;
    return true;
}

bool is_str_deco(const char* str) {
    if (str == NULL) return false;

    deco_t deco = str_to_deco(str);
    if (deco == DECO_NOT_SUPPORTED) return false;
    return true;
}

bool isofmt(ofmt_t ofmt) {
    switch (ofmt) {
        case (OFMT_PLAIN):
        case (OFMT_PDF):
        case (OFMT_MARKDOWN):
        case (OFMT_TEX):
        case (OFMT_ODT):
        case (OFMT_DOC):
            return true;
        default:
            break;
    }
    return false;
}

bool isdeco(deco_t deco) {
    switch (deco) {
        case (DECO_NONE):
        case (DECO_ALL):
        case (DECO_PAGE_BORDERS):
        case (DECO_HEADER):
        case (DECO_FOOTER):
            return true;
        default:
            break;
    }
    return false;
}
