#ifndef __LEXER_H__
#define __LEXER_H__

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
    TK_NUMBER,
    TK_NAME,
    TK_NEWLINE,
    TK_COMMENT,
} token_type_t;

typedef struct {
    token_type_t token;
    union {
        long i;
        double f;
        char *s;
    };
} token_t;

typedef struct {
    token_t tkn;
} statement_t;


token_t *read_token(const char **buff);

#endif  /* __LEXER_H__ */
