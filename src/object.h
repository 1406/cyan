#ifndef __CYAN_OBJECT_H__
#define __CYAN_OBJECT_H__

typedef enum {
    OBJ_NIL,
    OBJ_STRING,
    OBJ_NUMBER,
    OBJ_FUNCTION,
    OBJ_DATA,
    OBJ_LIST,
    OBJ_DICT,
    OBJ_THREAD,
} obj_t;

typedef struct object {
    obj_t type;
    char *name;
    void *substance;
    unsigned int count;
};

#endif  /* __CYAN_NUMBER_H__ */
