
typedef enum {
    TK_IF,
    TK_FOR,
    TK_WHILE,
    TK_FUNCTION,
    TK_RETURN,
    TK_LOCAL,
    TK_GLOBAL,
    TK_DO,
    TK_END,
    TK_BREAK,
    TK_INTEGER,
    TK_FLOAT,
    TK_STRING,
    TK_NAME,
} token_e;

typedef struct {
    token_e token;
    union {
        long i;
        double f;
        char *s;
    };
} token_t;

typedef struct {
    token_t tkn;
} statement_t;

