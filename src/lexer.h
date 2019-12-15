#ifndef __CYAN_LEXER_H__
#define __CYAN_LEXER_H__

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
} token_t;

struct token {
    token_t t;
    union {
        long i;
        double f;
        char *s;
    };
};


struct token *read_token(const char **buff);

#endif  /* __CYAN_LEXER_H__ */
