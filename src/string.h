#ifndef __CYAN_STRING_H__
#define __CYAN_STRING_H__

typedef enum {
    CODE_BYTE,
    CODE_ASCII,
    CODE_ANSI,
    CODE_UTF8,
    CODE_UTF16,
} str_t;

struct string {
    str_t t;
    char *s;
};

#endif  /* __CYAN_STRING_H__ */
