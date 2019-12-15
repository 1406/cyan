#include <stdbool.h>
#include <string.h>

#include "string.h"
#include "boolean.h"
#include "number.h"

struct string *strnew()
{
    struct string *str = malloc(sizeof(struct string));
    return str;
}

struct boolean *str2bool(struct string *str)
{
    struct boolean *bl = malloc(sizeof(struct boolean));
    bl->b = str->s != NULL && str->s[0] != '\0';
    return bl;
}

struct number *str2num(struct string *str)
{
    struct number *num = malloc(sizeof(struct number));
    num->t = NUM_INTEGER;
    return num;
}