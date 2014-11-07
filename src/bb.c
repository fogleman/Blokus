#include <stdio.h>
#include <string.h>
#include "bb.h"

static const int SLOTS = BIT_SLOTS(SQUARES);

void bb_clear(bb *a) {
    memset(a, 0, sizeof(bb));
}

void bb_copy(bb *dst, bb *src) {
    memcpy(dst, src, sizeof(bb));
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

int bb_lsb(bb *a) {
    int offset = 0;
    for (int i = 0; i < SLOTS; i++) {
        if (a->data[i]) {
            return offset + LSB(a->data[i]);
        }
        offset += INT_BIT;
    }
    return -1;
}
