#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "number.h"
#include "string.h"

const double EPS = 1e-15;

// int64最长情况, 19位数字, 1位符号, 1个\0
#define MAXINT64STRLEN 21

bool num2bool(struct number *num) {
    if (num->t == NUM_INTEGER) {
        return num->i != 0;
    } else {
        return fabs(num->d) > EPS;
    }
}

struct string *num2str(struct number *num) {
    struct string *str = malloc(sizeof(struct string));

    switch (num->t) {
    case NUM_INTEGER:
        str->s = malloc(MAXINT64STRLEN);
        sprintf(str->s, "%ld", num->i);
        break;
    case NUM_DOUBLE:
        str->s = malloc(MAXINT64STRLEN);
        sprintf(str->s, "%.15f", num->d);
        break;
    default:
        str->s = NULL;
        break;
    }
}