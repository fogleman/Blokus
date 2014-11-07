#ifndef BOARD_H
#define BOARD_H

#include "bb.h"

typedef struct {
    unsigned int player;
    unsigned int pieces[PLAYERS];
    bb filled[PLAYERS];
    bb border[PLAYERS];
    bb corner[PLAYERS];
} Board;

#endif
