#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <getopt.h>
#include <stdlib.h>

#include "statement.h"
#include "parser.h"
#include "lexer.h"

static int showversion() {
    printf("Cyan Version 0.0.0\n");
    return 0;
}

static int showusage() {
    printf("Usage:\n");
    return 0;
}

const char *short_options = "c:vh";
static struct option long_options[] = {
    {"compile", required_argument,  0,  'c'},
    {"version", no_argument,        0,  'v'},
    {"help",    no_argument,        0,  'h'},
    {0, 0, 0, 0},
};

/* 读取选项参数, 返回文件名所在的数组下标 */
static int getarguments(int argc, char *argv[]) {
    int opt, index;
    while ((opt = getopt_long(argc, argv, short_options, long_options, &index)) != -1)
    {
        switch (opt) {
        case 'c':
            printf("compile file %s", optarg);
            break;
        case 'v':
            showversion();
            exit(0);
            break;
        case 'h':
        case '?':
            showusage();
            exit(0);
        default:
            showusage();
            exit(1);
            break;
        }
    }
    return optind;
}

#define LINELEN 1024
static inline char *readline(FILE *stream, char *buffer, const char *prompt) {
    // print prompt
    if (prompt) {
        fputs(prompt, stdout);
        fflush(stdout);
    }
    // TODO: 如果没有读到换行符, 则有可能行没完
    return fgets(buffer, LINELEN, stream);
}

/* 不断地读取行, 做词法分析, 如果遇到特定的语法词, 则转入该语法的分析, 该语法再调用自己的语法分析函数 */
chunkstate_t *parser(FILE *stream, const char *prompt) {
    chunkstate_t *ast = (chunkstate_t *)malloc(sizeof(chunkstate_t));
    char *buffer = (char *)malloc(LINELEN);
    char *line = NULL;
    token_t *curr_token;
    for (int linenum = 1;; linenum++) {
        line = readline(stream, buffer, prompt);
        if (line == NULL) {
            printf("read stream failed,\n");
            break;
        }
        printf("read len %lu, read word %s\n", strlen(line), line);
        ast->currentline = linenum;
        curr_token = read_token(&line);
        printf("current token type %d\n", curr_token->token);
        if (curr_token->token == TK_COMMENT) {
            printf("comment is %s\n", curr_token->s);
        } else if (curr_token->token == TK_INTEGER) {
            printf("number is %ld\n", curr_token->i);
        } else if (curr_token->token == TK_FLOAT) {
            printf("number is %f\n", curr_token->f);
        } else if (curr_token->token == TK_STRING) {
            printf("string is %s\n", curr_token->s);
        } else {
            printf("----------------\n");
        }
        // curr_block 可能是一个没完成的语法, 因此每次都从这里开始
        switch (curr_token->token) {
        case TK_DO:
            /* code */
            break;

        default:
            break;
        }
        ast->curr_block->next = statement(curr_token, &line);
    }
    free(buffer);
    return ast;
}

int main (int argc, char *argv[]) {
    // 首先读取参数, 如果带了目标文件, 则从目标文件读取代码, 否则从标准输入读取
    int fidx = getarguments(argc, argv);
    if (fidx < argc) {
        while (fidx < argc) {
            FILE *stream = fopen(argv[fidx++], "r");
            parser(stream, NULL);
        }
    } else {
        parser(stdin, "cyan>> ");
    }

    return 0;
}