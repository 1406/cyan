#ifndef __CYAN_PARSER_H__
#define __CYAN_PARSER_H__

#include <stdio.h>

#include "lexer.h"
#include "statement.h"

#define LINELEN 1024

void parser(struct chunk *ast);
struct block *statement(struct token *tk, const char **buff);

#endif  /* __CYAN_PARSER_H__ */
