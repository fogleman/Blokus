#include "eval.h"

int evaluate(Board *board, int player) {
    int scores[PLAYERS];
    for (int i = 0; i < PLAYERS; i++) {
        int filled = bb_bits(&board->filled[i]);
        int border = bb_bits(&board->border[i]);
        int corner = bb_bits(&board->corner[i]);
        int score = filled * 10 - border + corner * 10;
        scores[i] = score;
    }
    int others = 0;
    for (int i = 0; i < PLAYERS; i++) {
        if (i != player) {
            others += scores[i];
        }
    }
    return scores[player] - others * 10;
}
