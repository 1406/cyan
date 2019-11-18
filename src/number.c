#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "number.h"
#include "string.h"

const double EPS = 1e-15;

// int64最长情况, 19位数字, 1位符号, 1个\0
#define MAXINT64STRLEN 21

bool num2bool(num_t *num) {
    if (num->n == NUM_INT) {
        return num->i != 0;
    } else {
        return fabs(num->d) > EPS;
    }
}

str_t *num2str(num_t *num) {
    str_t *str = (str_t *)malloc(sizeof(str_t));

    switch (num->n) {
    case NUM_INT:
        str->data = (char *)malloc(MAXINT64STRLEN);
        sprintf(str->data, "%l", num->i);
        break;
    case NUM_DOUBLE:
        str->data = (char *)malloc(MAXINT64STRLEN);
        sprintf(str->data, "%.15f", num->d);
        break;
    default:
        str->data = NULL;
        break;
    }
}