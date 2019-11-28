#include "lexer.h"
#include "statement.h"

blockstate_t *statement(token_t *token, const char **buff) {
    switch (token->token) {
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
