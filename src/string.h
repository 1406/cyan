
typedef enum {
    CODE_BYTE,
    CODE_ASCII,
    CODE_ANSI,
    CODE_UTF8,
    CODE_UTF16,
} code_e;

typedef struct {
    code_e code;
    char *data;
} str_t;

