#ifndef BB_H
#define BB_H

#include "common.h"

#define INT_BIT 32
#define BIT_SLOT(b) ((b) / INT_BIT)
#define BIT_MASK(b) (1 << ((b) % INT_BIT))
#define BIT_SET(a, b) ((a)[BIT_SLOT(b)] |= BIT_MASK(b))
#define BIT_CLEAR(a, b) ((a)[BIT_SLOT(b)] &= ~BIT_MASK(b))
#define BIT_TEST(a, b) ((a)[BIT_SLOT(b)] & BIT_MASK(b))
#define BIT_SLOTS(nb) ((nb + INT_BIT - 1) / INT_BIT)

typedef struct {
    unsigned int data[BIT_SLOTS(SQUARES)];
} bb;

void bb_clear(bb *a);
void bb_print(bb *a);
void bb_or(bb *out, bb *a, bb *b);

#endif
