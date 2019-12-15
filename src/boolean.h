#ifndef __CYAN_BOOLEAN_H__
#define __CYAN_BOOLEAN_H__

#include <stdbool.h>

#include "object.h"

struct boolean {
    struct object obj;
    bool b;
};

#endif  /* __CYAN_BOOLEAN_H__ */
