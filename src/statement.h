#ifndef __CYAN_STATEMENT_H__
#define __CYAN_STATEMENT_H__

#include <stdio.h>

#include "lexer.h"
#include "opcode.h"





enum CHUNK_STATUS {
    CS_DONE,
    CS_NEWLINE,
};







/* 代码块, 最基本的语法数结构, 以此组织整个脚本语法结构, 其他语法均依赖这个结构 */
struct block {
    int linenumber;
    struct token *tk;
    void *stmt;
    struct block *next;
};

struct expression_stmt {
    struct block block;
};

struct binary_expr_stmt {
    enum OP_CODE op;
    struct expression_stmt left;
    struct expression_stmt right;
};

struct unary_expr_stmt {
    enum OP_CODE op;
    struct expression_stmt expr;
};

struct do_stmt {
    struct block doblock;
    struct block expectblock;
    struct block finallyblock;
};

/* if statement is also elif statement */
struct if_stmt {
    struct expression_stmt expr;
    struct block truebranch;
    struct block falsebranch;
};

struct else_stmt {
    struct block elseblock;
};

struct while_stmt {
    struct expression_stmt expr;
    struct do_stmt doblock;
};

struct iterator_stmt {

};

struct for_stmt {
    struct iterator_stmt iter;
    struct do_stmt doblock;
};

struct function_stmt {
    struct do_stmt body;
};

/* chunk 是语法树的根节点 */
struct chunk {
    FILE *stream;
    char *prompt;
    char *buffer;
    struct token *curr_token;
    struct block *head_block;
    struct block *curr_block;
    int curr_line;          // 遇到换行符行号才加一, 如果是用反斜杠换行, 行号不变
    int curr_column;        // 遇到换行符这个置为0
    enum CHUNK_STATUS status;
    const char *currentpointer;
    const char *chunkname;  // 包名称, 用于import时排重
};

#endif  /* __CYAN_STATEMENT_H__ */
