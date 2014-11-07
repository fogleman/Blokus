#include <stdio.h>
#include <string.h>
#include "bb.h"

static const int SLOTS = BIT_SLOTS(SQUARES);

void bb_clear(bb *a) {
    memset(a, 0, sizeof(bb));
}

void bb_print(bb *a) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c ", BIT_TEST(a->data, SQ(x, y)) ? 'x' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

void bb_or(bb *out, bb *a, bb *b) {
    for (int i = 0; i < SLOTS; i++) {
        out->data[i] = a->data[i] | b->data[i];
    }
}
