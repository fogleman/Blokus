#ifndef BB_H
#define BB_H

#include <limits.h>
#include "common.h"

#define BIT_SLOT(b) ((b) / CHAR_BIT)
#define BIT_MASK(b) (1 << ((b) % CHAR_BIT))
#define BIT_SET(a, b) ((a)[BIT_SLOT(b)] |= BIT_MASK(b))
#define BIT_CLEAR(a, b) ((a)[BIT_SLOT(b)] &= ~BIT_MASK(b))
#define BIT_TEST(a, b) ((a)[BIT_SLOT(b)] & BIT_MASK(b))
#define BIT_SLOTS(nb) ((nb + CHAR_BIT - 1) / CHAR_BIT)

typedef struct {
    char data[BIT_SLOTS(SQUARES)];
} bb;

void bb_clear(bb *a);
void bb_print(bb *a);
void bb_or(bb *out, bb *a, bb *b);

#endif
