#ifndef __NUMBER_H__
#define __NUMBER_H__

typedef enum {
    NUM_INT,
    NUM_DOUBLE,
} num_type_t;

typedef struct {
    num_type_t n;
    union {
        long i;
        double d;
    };
} num_t;

#endif  /* __NUMBER_H__ */
