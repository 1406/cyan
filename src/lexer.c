#include <ctype.h>
#include <stdbool.h>
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lexer.h"

static const char * const reserved[] = {
    "true", "false",
    "null", "undefined",
    "local", "global",
    "if", "then", "else", "elif", "endif",
    "do", "end", "except", "finally", "break",
    "for", "in", "while", "continue",
    "function", "return",
    "import",
};

/*************************************
 * 支持的数字格式, 负号被当作运算符, 因此不作为阅读数字的一部分:
 * 0                                整数0
 * [1-9][0-9]*                      整数
 * 0.[0-9]+                         浮点数
 * [1-9][0-9]*.[0-9]+               浮点数
 * 0[Xx][0-9a-fA-F]+                十六进制整数, a-f小写, A-F大写
 * 0[Oo]?[0-7]+                     八进制整数
 * 0[Bb][01]+                       二进制整数
 * [0-9]+(.[0-9]+)?[Ee][+-]?[0-9]+  科学记数法浮点数, e小写, E大写
 * 首位仅能数字开头, 其中0开头的后仅能跟进制符号和小数点以及八进制数或空白
**/
token_t *read_number(char **strbuf) {
    char *str = *strbuf;

    token_t *result = (token_t *)malloc(sizeof (token_t));
    assert(result != NULL);
    result->token = TK_INTEGER;

    // 先读首二位, 这两位信息量很大, 很有可能就此确定该怎么读, 如果非10进制, 这里就能确定了, 10进制的情况如果读到了小数点, 也能确定就读浮点数了
    if (*str == '0') {
        str++;
        switch (*str) {
        case '.':
            // 浮点数, 还需检查下一位, 点后必须是数字, 但strtod可以小数点开头
            assert(isdigit(*(str + 1)));
            result->token = TK_FLOAT;
            result->f = strtod(str, &str);
            break;
        case 'X':
        case 'x':
            // 十六进制
            str++;
            assert(isxdigit(*str));
            result->i = strtol(str, &str, 16);
            break;
        case 'O':
        case 'o':
            // strtol 不识别0O和0o标识
            str++;
            assert(*str >= '0' && *str < '8');
        case '0' ... '7':
            // 八进制
            result->i = strtol(str, &str, 8);
            break;
        case 'B':
        case 'b':
            // 二进制
            str++;
            assert(*(str + 1) == '0' || *(str + 1) == '1');
            result->i = strtol(str + 2, &str, 2);
            break;
        default:
            result->i = strtol(str, &str, 0);
            break;
        }
    } else {
        // 非0, 先按整数读, 如果读完后面是小数点或大小写Ee, 则按浮点数读
        char *next;
        result->i = strtol(str, &next, 10);
        switch (*next) {
        case 'E':
        case 'e':
            assert(*(next + 1) == '-' || *(next + 1) == '+' || isdigit(*(next + 1)));
        case '.':
            assert(isdigit(*(next + 1)));
            result->token = TK_FLOAT;
            result->f = strtod(str, &str);
            break;
        default:
            str = next;
            break;
        }
    }
    assert(*str == '\0' || isspace(*str) || (ispunct(*str) && *str != '_'));
    return result;
}

token_t *read_string(char **strbuf) {
    char *str = *strbuf;
    char *start = str;
    assert(*start == '\'' || *start == '"');
    while (*str) {
        if (*str == '\\') {
            str += 2;
        }
        if (*str == *start) {
            break;
        }
        str++;
    }
    token_t *result = (token_t *)malloc(sizeof (token_t));
    assert(result != NULL);
    int length = str - start;
    result->s = (char *)malloc(length + 1);
    memcpy(result->s, start, length);
    result->s[length] = '\0';
    result->token = TK_STRING;
    return result;
}

token_t *read_identifier(char **strbuf) {
    char *str = *strbuf;
    char *start = str;
    while (*str) {
        if (isalpha(*str) || isalnum(*str) || *str == '_') {
            str++;
        } else {
            break;
        }
    }
    
    token_t *result = (token_t *)malloc(sizeof (token_t));
    assert(result != NULL);
    int length = str - start;
    result->s = (char *)malloc(length + 1);
    memcpy(result->s, start, length);
    result->s[length] = '\0';

    // 此处需要判断是否关键字, 然后为token赋值
    // FIXME: 先用简单粗暴的方法判断, 以后再看有没有好的算法, 这里就需要token_e和reserved序号一致
    for (int i = 0; i < 23; i++) {
        if (!strcmp(result->s, reserved[i])) {
            result->token = i;
            return result;
        }
    }
    result->token = TK_NAME;
    return result;
}

char *read_comment() {

}

token_e read_token(const char *buff) {
    switch (*buff) {
    case '\r':
    case '\n':
        increasenum();
    case ' ':
    case '\t':
    case '\v':
    case '\f':
        /* space */
        return read_token(buff++);
    case '#':
        /* comment */
        return read_comment();
    case ';':
        /* split expr */
        break;
    case ',':
        /* split expr */
        break;
    case '=':
        /* = and == */
        break;
    case '!':
        /* ! and != */
        break;
    case '>':
        /* > and >= */
        break;
    case '<':
        /* < and <= */
        break;
    case '+':
        /* + and += */
        break;
    case '-':
        /* - and -= */
        break;
    case '*':
        /* * and *= */
        break;
    case '/':
        /* / and /= */
        break;
    case '%':
        /* % and %= */
        break;
    case '^':
        /* ^ and ^= */
        break;
    case '.':
        /* . */
        break;
    case '\'':
        /* string unformatable */
        break;
    case '"':
        /* string */
        break;
    case '0' ... '9':
        /* number */
        break;
    default:
        /* label */
        break;
    }
}

token_e lexer(chunkstate_t *ast, const char *buff) {
}
