#include <string.h>
#include "move.h"
#include "placement.h"

void do_move(Board *board, Move *move, Board *undo) {
    if (undo) {
        memcpy(undo, board, sizeof(Board));
    }
    Placement *placement = &placements[move->pattern][move->square];
    Pattern *pattern = patterns + move->pattern;
    bb *filled = &board->filled[board->player];
    bb *border = &board->border[board->player];
    bb *corner = &board->corner[board->player];
    bb_or(filled, filled, &placement->filled);
    bb_or(border, border, &placement->border);
    bb_or(corner, corner, &placement->corner);
    bb_and_not(corner, corner, border);
    for (int i = 0; i < PLAYERS; i++) {
        if (i == board->player) {
            continue;
        }
        bb *other_border = &board->border[i];
        bb *other_corner = &board->corner[i];
        bb_or(other_border, other_border, &placement->filled);
        bb_and_not(other_corner, other_corner, other_border);
    }
    board->pieces[board->player] &= ~(1 << pattern->piece);
    board->player = (board->player + 1) % PLAYERS;
}

void undo_move(Board *board, Board *undo) {
    memcpy(board, undo, sizeof(Board));
}
