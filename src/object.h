#ifndef __CYAN_OBJECT_H__
#define __CYAN_OBJECT_H__

enum OBJ_TYPE {
    OBJ_NIL,
    OBJ_STRING,
    OBJ_NUMBER,
    OBJ_FUNCTION,
    OBJ_DATA,
    OBJ_LIST,
    OBJ_DICT,
    OBJ_THREAD,
};

struct object {
    enum OBJ_TYPE type;
    char *name;
    void *substance;
    unsigned int count;
};

#endif  /* __CYAN_NUMBER_H__ */
