#ifndef _NUMBER_H_
#define _NUMBER_H_

typedef enum {
    NUM_INT,
    NUM_DOUBLE,
} num_e;

typedef struct {
    num_e n;
    union {
        long i;
        double d;
    };
} num_t;

#endif