#include "parser.h"
#include "statement.h"

struct block *funcstat(const char **buff) {

}

struct block *returnstat(const char **buff) {
    
}

struct block *dostat(const char **buff) {
    
}

struct block *whilestat(const char **buff) {
    
}

struct block *forstat(const char **buff) {
    
}

struct block *breakstat(const char **buff) {
    
}

struct block *ifstat(const char **buff) {
    
}

struct block *exprstat(const char **buff) {
    
}

struct block *statement(struct token *tk, const char **buff) {
    switch (tk->t) {
    case TK_FUNCTION:
        funcstat(buff);
        break;
    case TK_RETURN:
        returnstat(buff);
        break;
    case TK_DO:
        dostat(buff);
        break;
    case TK_WHILE:
        whilestat(buff);
        break;
    case TK_FOR:
        forstat(buff);
        break;
    case TK_BREAK:
        breakstat(buff);
        break;
    case TK_IF:
        ifstat(buff);
        break;
    default:
        exprstat(buff);
        break;
    }
}

#define LINELEN 1024
static inline char *readline(FILE *stream, char *buffer, const char *prompt) {
    // print prompt
    if (prompt) {
        fputs(prompt, stdout);
        fflush(stdout);
    }
    // TODO: 如果没有读到换行符, 则有可能行没完
    return fgets(buffer, LINELEN, stream);
}

/* 不断地读取行, 做词法分析, 如果遇到特定的语法词, 则转入该语法的分析, 该语法再调用自己的语法分析函数 */
struct chunk *parser(FILE *stream, const char *prompt) {
    struct chunk *ast = malloc(sizeof(struct chunk));
    char *buffer = malloc(LINELEN);
    char *line = NULL;
    struct token *curr_token;
    for (int linenum = 1;; linenum++) {
        line = readline(stream, buffer, prompt);
        if (line == NULL) {
            printf("read stream failed,\n");
            break;
        }
        printf("read len %lu, read word %s\n", strlen(line), line);
        ast->currentline = linenum;
        curr_token = read_token(&line);
        printf("current token type %d\n", curr_token->t);
        if (curr_token->t == TK_COMMENT) {
            printf("comment is %s\n", curr_token->s);
        } else if (curr_token->t == TK_INTEGER) {
            printf("number is %ld\n", curr_token->i);
        } else if (curr_token->t == TK_FLOAT) {
            printf("number is %f\n", curr_token->f);
        } else if (curr_token->t == TK_STRING) {
            printf("string is %s\n", curr_token->s);
        } else {
            printf("----------------\n");
        }
        // curr_block 可能是一个没完成的语法, 因此每次都从这里开始
        switch (curr_token->t) {
        case TK_DO:
            /* code */
            break;

        default:
            break;
        }
        // ast->curr_block->next = statement(curr_token, &line);
    }
    free(buffer);
    return ast;
}
