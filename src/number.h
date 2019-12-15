#ifndef __CYAN_NUMBER_H__
#define __CYAN_NUMBER_H__

typedef enum {
    NUM_INTEGER,
    NUM_DOUBLE,
    NUM_NAN,
} num_t;

struct number {
    num_t t;
    union {
        long i;
        double d;
    };
};

#endif  /* __CYAN_NUMBER_H__ */
