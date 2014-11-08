#include <string.h>
#include "gen.h"
#include "pattern.h"
#include "placement.h"
#include "util.h"

int gen_moves(Board *board, Move *moves) {
    int index = 0;
    int seen[SQUARES];
    bb *border = &board->border[board->player];
    bb *corner = &board->corner[board->player];
    unsigned int pieces = board->pieces[board->player];
    int corners[SQUARES];
    int ncorners = bb_get_bits(corner, corners);
    for (int p = 0; p < PATTERNS; p++) {
        Pattern *pattern = patterns + p;
        if ((pieces & (1 << pattern->piece)) == 0) {
            continue; // piece already used
        }
        memset(seen, 0, sizeof(seen));
        for (int i = 0; i < ncorners; i++) {
            int bit = corners[i];
            for (int j = 0; j < CELLS; j++) {
                int sq = pattern_squares[p][bit][j];
                if (sq < 0) {
                    break;
                }
                if (seen[sq]) {
                    continue;
                }
                seen[sq] = 1;
                Placement *placement = &placements[p][sq];
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

int gen_random_move(Board *board, Move *move) {
    bb *border = &board->border[board->player];
    bb *corner = &board->corner[board->player];
    unsigned int pieces = board->pieces[board->player];
    if (pieces == 0) {
        return 0;
    }
    int corners[SQUARES];
    int ncorners = bb_get_bits(corner, corners);
    if (ncorners == 0) {
        return 0;
    }
    for (int i = 0; i < 256; i++) {
        int p = rand_int(PATTERNS);
        Pattern *pattern = patterns + p;
        if ((pieces & (1 << pattern->piece)) == 0) {
            continue;
        }
        int bit = corners[rand_int(ncorners)];
        int ncells = 0;
        for (int i = 0; i < CELLS; i++) {
            ncells += pattern_squares[p][bit][i] >= 0;
        }
        if (ncells == 0) {
            continue;
        }
        int j = rand_int(ncells);
        int sq = pattern_squares[p][bit][j];
        Placement *placement = &placements[p][sq];
        if (bb_intersects(&placement->filled, border)) {
            continue;
        }
        move->pattern = p;
        move->square = sq;
        return 1;
    }
    Move moves[MOVES];
    int count = gen_moves(board, moves);
    if (count == 0) {
        return 0;
    }
    int index = rand_int(count);
    move->pattern = moves[index].pattern;
    move->square = moves[index].square;
    return 1;
}
