#ifndef BOARD_H
#define BOARD_H

#include "bb.h"

typedef struct {
    unsigned int player;
    unsigned int pieces[PLAYERS];
    unsigned int score[PLAYERS];
    bb filled[PLAYERS];
    bb border[PLAYERS];
    bb corner[PLAYERS];
} Board;

void board_clear(Board *board);
void board_copy(Board *dst, Board *src);
void board_print(Board *board);

#endif
