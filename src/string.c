#include <stdbool.h>

#include "string.h"

bool str2bool(str_t *str) {
    return str->data == NULL || str->data[0] == '\0';
}