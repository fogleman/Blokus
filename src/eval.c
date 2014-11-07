#include "eval.h"

int evaluate(Board *board, int player) {
    int filled1 = bb_bits(&board->filled[0]);
    int border1 = bb_bits(&board->border[0]);
    int corner1 = bb_bits(&board->corner[0]);
    int filled2 = bb_bits(&board->filled[1]);
    int border2 = bb_bits(&board->border[1]);
    int corner2 = bb_bits(&board->corner[1]);
    int p1 = filled1 * 10 - border1 + corner1;
    int p2 = filled2 * 10 - border2 + corner2;
    if (player == 0) {
        return p1 - p2;
    }
    else {
        return p2 - p1;
    }
}
