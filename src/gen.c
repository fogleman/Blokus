#include <string.h>
#include "gen.h"
#include "pattern.h"
#include "placement.h"

int gen_move(Board *board, Placement *placement, Move *move) {
    move->pattern = 0;
    return 1;
}

int gen_moves(Board *board, Move *moves) {
    int index = 0;
    int seen[SQUARES];
    bb *border = &board->border[board->player];
    bb *corner = &board->corner[board->player];
    unsigned int pieces = board->pieces[board->player];
    for (int p = 0; p < PATTERNS; p++) {
        Pattern *pattern = patterns + p;
        if ((pieces & (1 << pattern->piece)) == 0) {
            continue; // piece already used
        }
        memset(seen, 0, sizeof(seen));
        bb candidates;
        bb_copy(&candidates, corner);
        while (1) {
            int bit = bb_pop_lsb(&candidates);
            if (bit < 0) {
                break;
            }
            for (int i = 0; i < CELLS; i++) {
                int sq = pattern_squares[p][bit][i];
                if (sq < 0) {
                    break;
                }
                if (seen[sq]) {
                    continue;
                }
                seen[sq] = 1;
                Placement *placement = &placements[p][sq];
                if (!placement->valid) {
                    continue;
                }
                if (bb_intersects(&placement->filled, border)) {
                    continue;
                }
                Move *move = moves + index;
                move->pattern = p;
                move->square = sq;
                index++;
            }
        }
    }
    return index;
}
