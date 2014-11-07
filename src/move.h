#ifndef MOVE_H
#define MOVE_H

#include "board.h"
#include "move.h"

typedef struct {
    int pattern;
    int square;
} Move;

void do_move(Board *board, Move *move, Board *undo);
void undo_move(Board *board, Board *undo);

#endif
