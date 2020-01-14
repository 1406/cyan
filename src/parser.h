#ifndef __CYAN_PARSER_H__
#define __CYAN_PARSER_H__

#include <stdio.h>

#include "lexer.h"

struct chunk *parser(FILE *stream, const char *prompt);
struct block *statement(struct token *tk, const char **buff);

#endif  /* __CYAN_PARSER_H__ */
