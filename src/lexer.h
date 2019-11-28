#ifndef __LEXER_H__
#define __LEXER_H__

typedef enum {
    TK_IF, TK_THEN, TK_ELIF, TK_ELSE, TK_ENDIF,
    TK_FOR, TK_IN, TK_WHILE, TK_CONTINUE,
    TK_FUNCTION, TK_RETURN,
    TK_LOCAL, TK_GLOBAL,
    TK_DO, TK_END, TK_BREAK, TK_EXCEPT, TK_FINALLY,
    TK_INTEGER, TK_FLOAT, TK_STRING,
    TK_IMPORT, TK_AS,
    TK_NAME,
    TK_NEWLINE,
    TK_COMMENT,
    TK_EQ, TK_NE, TK_GT, TK_TE, TK_LT, TK_LE,
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
