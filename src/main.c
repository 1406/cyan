#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <stdlib.h>
#include <assert.h>

#include "parser.h"

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

int main (int argc, char *argv[]) {
    struct chunk *ast = malloc(sizeof(struct chunk));
    assert(ast != NULL);

    // 首先读取参数, 如果带了目标文件, 则从目标文件读取代码, 否则从标准输入读取
    int fidx = getarguments(argc, argv);
    if (fidx < argc) {
        while (fidx < argc) {
            ast->stream = fopen(argv[fidx++], "r");
            ast->prompt = NULL;
            ast->buffer = malloc(LINELEN);
            ast->curr_line = 0;
            parser(ast);
        }
    } else {
        ast->stream = stdin;
        ast->prompt = "cyan>> ";
        ast->buffer = malloc(LINELEN);
        ast->curr_line = 0;
        parser(ast);
    }

    return 0;
}