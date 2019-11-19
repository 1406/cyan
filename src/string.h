#ifndef __STRING_H__
#define __STRING_H__

typedef enum {
    CODE_BYTE,
    CODE_ASCII,
    CODE_ANSI,
    CODE_UTF8,
    CODE_UTF16,
} codec_type_t;

typedef struct {
    codec_type_t code;
    char *data;
} str_t;

#endif  /* __STRING_H__ */
