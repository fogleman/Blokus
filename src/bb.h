#ifndef BB_H
#define BB_H

#include "common.h"

#define LSB(x) (__builtin_ctz(x))
#define MSB(x) (__builtin_clz(x))
#define BITS(x) (__builtin_popcount(x))

#define POP_LSB(b, x) b = LSB(x); x &= ~BIT(b);
#define POP_MSB(b, x) b = MSB(x); x &= ~BIT(b);

#define INT_BIT 32
#define BIT_SLOTS(n) (((n) + INT_BIT - 1) / INT_BIT)
#define BIT_SLOT(b) ((b) / INT_BIT)
#define BIT_MASK(b) (1 << ((b) % INT_BIT))
#define BIT_SET(a, b) ((a)[BIT_SLOT(b)] |= BIT_MASK(b))
#define BIT_UNSET(a, b) ((a)[BIT_SLOT(b)] &= ~BIT_MASK(b))
#define BIT_TEST(a, b) ((a)[BIT_SLOT(b)] & BIT_MASK(b))

#define BB_SET(a, b) BIT_SET((a).data, b)
#define BB_UNSET(a, b) BIT_UNSET((a).data, b)
#define BB_TEST(a, b) BIT_TEST((a).data, b)

typedef struct {
    unsigned int data[BIT_SLOTS(SQUARES)];
} bb;

void bb_clear(bb *a);
void bb_copy(bb *dst, bb *src);
void bb_print(bb *a);
void bb_or(bb *out, bb *a, bb *b);
int bb_lsb(bb *a);

#endif
