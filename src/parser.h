typedef struct {

} block;


typedef struct {
    block blk;
} chunk;


chunkstate_t *parser(FILE *stream, const char *prompt) {