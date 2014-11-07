#include "common.h"
#include "placement.h"

Placement placements[PATTERNS][SQUARES];

void init_placement(Pattern *pattern, int sq, Placement *placement) {
    int x = sq % WIDTH;
    int y = sq / WIDTH;
    placement->valid = 1;
    bb_clear(&placement->filled);
    bb_clear(&placement->border);
    bb_clear(&placement->corner);
    for (int j = 0; j < 7; j++) {
        for (int i = 0; i < 7; i++) {
            int t = pattern->data[j][i];
            int tx = x + i - 1;
            int ty = y + j - 1;
            if (tx < 0 || ty < 0 || tx >= WIDTH || ty >= HEIGHT) {
                if (t == FILLED) {
                    placement->valid = 0;
                }
                continue;
            }
            int idx = SQ(tx, ty);
            switch (t) {
                case FILLED:
                    BB_SET(placement->filled, idx);
                    BB_SET(placement->border, idx);
                    break;
                case BORDER:
                    BB_SET(placement->border, idx);
                    break;
                case CORNER:
                    BB_SET(placement->corner, idx);
                    break;
            }
        }
    }
}

void init_placements() {
    for (int p = 0; p < PATTERNS; p++) {
        for (int s = 0; s < SQUARES; s++) {
            Pattern *pattern = patterns + p;
            init_placement(pattern, s, &placements[p][s]);
        }
    }
}
