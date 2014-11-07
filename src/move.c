#include "common.h"
#include "move.h"

Move pattern_moves[PATTERNS][SQUARES];

void init_move(Pattern *pattern, int sq, Move *move) {
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

void init_moves() {
    for (int p = 0; p < PATTERNS; p++) {
        for (int s = 0; s < SQUARES; s++) {
            Pattern *pattern = patterns + p;
            init_move(pattern, s, &pattern_moves[p][s]);
        }
    }
}
