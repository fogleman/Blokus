#ifndef MOVE_H
#define MOVE_H

#include "bb.h"
#include "move.h"
#include "pattern.h"

typedef struct {
    bb filled;
    bb border;
    bb corner;
    char valid;
} Move;

extern Move pattern_moves[PATTERNS][SQUARES];

void init_move(Pattern *pattern, int sq, Move *move);
void init_moves();

#endif
