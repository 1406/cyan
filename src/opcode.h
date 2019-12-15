#ifndef __CYAN_OPCDOE_H__
#define __CYAN_OPCODE_H__

typedef enum {
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_MOD,

    OP_EQ,
    OP_NE,
    OP_LT,
    OP_LE,
    OP_GT,
    OP_GE,

    OP_CALL,
    OP_RETURN,
} opcode_t;

#endif  /* __CYAN_OPCODE_H__ */