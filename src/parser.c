#include <assert.h>

#include "parser.h"

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

void read_function(struct chunk *ast) {

}

void read_for(struct chunk *ast) {
    
}

void read_while(struct chunk *ast) {
    
}

void read_if(struct chunk *ast) {
    
}

void read_local(struct chunk *ast) {
    
}

void read_global(struct chunk *ast) {
    
}

void read_import(struct chunk *ast) {
    
}

void read_expr(struct chunk *ast) {
    
}

static inline char *readline(struct chunk *ast) {
    // print prompt
    if (ast->prompt) {
        fputs(ast->prompt, stdout);
        fflush(stdout);
    }
    // 如果没有读到换行符, 则有可能行没完
    if (ast->status == CS_NEWLINE) {
        ast->curr_line++;
        ast->curr_column = 0;
    }
    return fgets(ast->buffer, LINELEN, ast->stream);
}

/* 不断地读取行, 做词法分析, 如果遇到特定的语法词, 则转入该语法的分析, 该语法再调用自己的语法分析函数 */
void parser(struct chunk *ast) {
    assert(ast != NULL);

    char *line = NULL;
    if (ast->status == CS_NEWLINE) {
        line = readline(ast);
        if (line == NULL) {
            printf("read stream failed,\n");
            return;
        }
        printf("read len %lu, read word %s\n", strlen(line), line);
    }

    ast->curr_token = read_token(&line);
    printf("current token type %d\n", ast->curr_token->t);
    switch (ast->curr_token->t) {
    case TK_FUNCTION:
        ast->curr_block->next = malloc(sizeof(struct function_stmt));
        ast->curr_block = ast->curr_block->next;
        read_function(ast);
        break;

    case TK_FOR:
        ast->curr_block->next = malloc(sizeof(struct for_stmt));
        ast->curr_block = ast->curr_block->next;
        read_for(ast);
        break;

    case TK_WHILE:
        ast->curr_block->next = malloc(sizeof(struct while_stmt));
        ast->curr_block = ast->curr_block->next;
        read_while(ast);
        break;

    case TK_IF:
        ast->curr_block->next = malloc(sizeof(struct while_stmt));
        ast->curr_block = ast->curr_block->next;
        read_if(ast);
        break;

    case TK_LOCAL:
        ast->curr_block->next = malloc(sizeof(struct while_stmt));
        ast->curr_block = ast->curr_block->next;
        read_local(ast);
        break;

    case TK_GLOBAL:
        ast->curr_block->next = malloc(sizeof(struct while_stmt));
        ast->curr_block = ast->curr_block->next;
        read_global(ast);
        break;

    case TK_IMPORT:
        ast->curr_block->next = malloc(sizeof(struct while_stmt));
        ast->curr_block = ast->curr_block->next;
        read_import(ast);
        break;

    case TK_NAME:
        ast->curr_block->next = malloc(sizeof(struct while_stmt));
        ast->curr_block = ast->curr_block->next;
        read_expr(ast);
        break;

    case TK_COMMENT:
    case TK_NEWLINE:
        // 这两个在 read_token 时候处理过了
        break;

    default:
        assert(0 != 0);
        break;
    }
}
