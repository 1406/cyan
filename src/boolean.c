#include <string.h>

#include "boolean.h"
#include "number.h"
#include "string.h"

struct string *bool2str(struct boolean *bl)
{
    struct string *str = malloc(sizeof(struct string));
    str->t = CODE_ASCII;
    if (bl->b) {
        str->s = malloc(5);
        strncpy(str->s, "true", 5);
    } else {
        str->s = malloc(6);
        strncpy(str->s, "false", 6);
    }
    return str;
}

struct number *bool2num(struct boolean *bl)
{
    struct number *num = malloc(sizeof(struct number));
    num->t = NUM_INTEGER;
    if (bl->b) {
        num->i = 1;
    } else {
        num->i = 0;
    }
    return num;
}
