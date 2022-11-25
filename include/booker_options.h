#ifndef BOOKER_OPTIONS_H
#define BOOKER_OPTIONS_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

enum ofmt {
    OFMT_NOT_SUPPORTED = -1,
    OFMT_PLAIN,
    OFMT_PDF,
    OFMT_MARKDOWN,
    OFMT_TEX,
    OFMT_ODT,
    OFMT_DOC,
};
typedef enum ofmt ofmt_t;

static const char* OFMT_STR_PLAIN    = "plain";
static const char* OFMT_STR_PDF      = "pdf";
static const char* OFMT_STR_MARKDOWN = "mkd";
static const char* OFMT_STR_TEX      = "tex";
static const char* OFMT_STR_ODT      = "odt";
static const char* OFMT_STR_DOC      = "doc";


enum deco {
    DECO_NOT_SUPPORTED =  -1,
    DECO_NONE          = 0x00,
    DECO_ALL           = 0x01,
    DECO_PAGE_BORDERS  = 0x02,
    DECO_HEADER        = 0x04,
    DECO_FOOTER        = 0x08,
};
typedef enum deco deco_t;

static const char* DECO_STR_NONE         = "none";
static const char* DECO_STR_ALL          = "all";
static const char* DECO_STR_PAGE_BORDERS = "page-borders";
static const char* DECO_STR_HEADER       = "header";
static const char* DECO_STR_FOOTER       = "footer";


struct opts {
    ofmt_t ofmt;
    deco_t deco;
};
typedef struct opts opts_t;


ofmt_t str_to_ofmt(const char* str);
deco_t str_to_deco(const char* str);

bool is_str_ofmt(const char* str);
bool is_str_deco(const char* str);

bool isofmt(ofmt_t ofmt);
bool isdeco(deco_t deco);

#endif // BOOKER_OPTIONS_H
