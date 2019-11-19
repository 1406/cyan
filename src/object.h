#ifndef __OBJECT_H__
#define __OBJECT_H__

typedef enum {
    T_NIL,
    T_STRING,
    T_NUMBER,
    T_FUNCTION,
    T_DATA,
    T_LIST,
    T_DICT,
    T_THREAD,
} type_t;

typedef struct {
    type_t type;
    char *name;
} object;

#endif  /*  __NUMBER_H__ */
