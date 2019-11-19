#ifndef __PARSER_H__
#define __PARSER_H__

typedef struct {

} block;


typedef struct {
    block blk;
} chunk;


chunkstate_t *parser(FILE *stream, const char *prompt);
void statement(statement_t *stmt);

#endif  /* __PARSER_H__ */
