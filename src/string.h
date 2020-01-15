#ifndef __CYAN_STRING_H__
#define __CYAN_STRING_H__

enum STR_TYPE {
    CODE_BYTE,
    CODE_ASCII,
    CODE_ANSI,
    CODE_UTF8,
    CODE_UTF16,
};

struct string {
    enum STR_TYPE t;
    char *s;
};

#endif  /* __CYAN_STRING_H__ */
