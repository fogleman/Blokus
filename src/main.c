#include <stdio.h>
#include <string.h>
#include "bb.h"
#include "common.h"
#include "pattern.h"

typedef struct {
    char valid;
    bb filled;
    bb border;
    bb corner;
} Move;

void create_move(Pattern *pattern, int sq, Move *move) {
    int x = sq % WIDTH;
    int y = sq / WIDTH;
    move->valid = 1;
    bb_clear(&move->filled);
    bb_clear(&move->border);
    bb_clear(&move->corner);
    for (int j = 0; j < 7; j++) {
        for (int i = 0; i < 7; i++) {
            int t = pattern->data[j][i];
            int tx = x + i - 1;
            int ty = y + j - 1;
            if (tx < 0 || ty < 0 || tx >= WIDTH || ty >= HEIGHT) {
                if (t == FILLED) {
                    move->valid = 0;
                }
                continue;
            }
            int idx = SQ(tx, ty);
            switch (t) {
                case FILLED:
                    BIT_SET(move->filled.data, idx);
                    BIT_SET(move->border.data, idx);
                    break;
                case BORDER:
                    BIT_SET(move->border.data, idx);
                    break;
                case CORNER:
                    BIT_SET(move->corner.data, idx);
                    break;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    Move move;
    init_pattern_squares();
    int n = 0;
    for (int p = 0; p < PATTERNS; p++) {
        // for (int s = 0; s < SQUARES; s++) {
            for (int i = 0; i < 5; i++) {
                int sq = pattern_squares[p][60][i];
                if (sq < 0) {
                    continue;
                }
                create_move(&patterns[p], sq, &move);
                bb_print(&move.filled);
                n++;
                // break;
            }
        // }
    }
    printf("%d\n", n);
    return 0;
}
