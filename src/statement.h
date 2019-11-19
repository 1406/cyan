#ifndef __STATEMENT_H__
#define __STATEMENT_H__



#include "lexer.h"














/* 代码块, 最基本的语法数结构, 以此组织整个脚本语法结构, 其他语法均依赖这个结构 */
typedef struct blockstate {
    token_t *token;
    int linenumber;
    void *stmt;
    struct blockstate *next;
} blockstate_t;

typedef struct {
    blockstate_t block;
} expressionstate_t;

typedef struct {
    token_t *token;
    expressionstate_t left;
    expressionstate_t right;
} binaryexpressionstate_t;

typedef struct {
    token_t *token;
    expressionstate_t expr;
} unaryexpressionstate_t;

typedef struct {
    blockstate_t block;
} dostate_t;


typedef struct {
    expressionstate_t expr;
    blockstate_t truebranch;
    blockstate_t falsebranch;
} ifstate_t, elifstate_t;

typedef struct {
    blockstate_t elseblock;
} elsestate_t;

typedef struct {
    expressionstate_t expr;
    dostate_t doblock;
} whilestate_t;

typedef struct {

} iteratorstate_t;

typedef struct {
    iteratorstate_t iter;
    dostate_t doblock;
} forstate_t;

typedef struct {

} functionstate_t;

typedef struct {
    blockstate_t block;
    int currentline;
    // token_t currenttoken;
    const char *currentpointer;
    const char *chunkname;  // 包名称, 用于import时排重
} chunkstate_t;

#endif  /* __STATEMENT_H__ */
