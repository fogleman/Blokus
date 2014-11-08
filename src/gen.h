#ifndef GEN_H
#define GEN_H

#include "board.h"
#include "move.h"

int gen_moves(Board *board, Move *moves);
int gen_random_move(Board *board, Move *move);

#endif
