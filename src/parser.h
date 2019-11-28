#ifndef __PARSER_H__
#define __PARSER_H__

typedef struct {

} block;


typedef struct {
    block blk;
} chunk;


chunkstate_t *parser(FILE *stream, const char *prompt);
blockstate_t *statement(token_t *token, const char **buff);

#endif  /* __PARSER_H__ */
