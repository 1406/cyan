#include "lexer.h"

void statement(statement_t *stmt) {
    switch (stmt->tkn.token) {
    case TK_FUNCTION:
        funcstat(stmt);
        break;
    case TK_RETURN:
        returnstat(stmt);
        break;
    case TK_DO:
        dostat(stmt);
        break;
    case TK_WHILE:
        whilestat(stmt);
        break;
    case TK_FOR:
        forstat(stmt);
        break;
    case TK_BREAK:
        breakstat(stmt);
        break;
    case TK_IF:
        ifstat(stmt);
        break;
    default:
        exprstat(stmt);
        break;
    }
}
