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

void bb_and_not(bb *out, bb *a, bb *b) {
    for (int i = 0; i < SLOTS; i++) {
        out->data[i] = a->data[i] & ~b->data[i];
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

int bb_pop_lsb(bb *a) {
    int bit = bb_lsb(a);
    if (bit >= 0) {
        BIT_UNSET(a->data, bit);
    }
    return bit;
}

int bb_intersects(bb *a, bb *b) {
    for (int i = 0; i < SLOTS; i++) {
        if (a->data[i] & b->data[i]) {
            return 1;
        }
    }
    return 0;
}

int bb_bits(bb *a) {
    int result = 0;
    for (int i = 0; i < SLOTS; i++) {
        result += BITS(a->data[i]);
    }
    return result;
}
