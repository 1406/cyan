#ifndef __CYAN_NUMBER_H__
#define __CYAN_NUMBER_H__

enum NUM_TYPE {
    NUM_INTEGER,
    NUM_DOUBLE,
    NUM_NAN,
};

struct number {
    enum NUM_TYPE t;
    union {
        long i;
        double d;
    };
};

#endif  /* __CYAN_NUMBER_H__ */
