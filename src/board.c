#include <string.h>
#include "board.h"

void board_clear(Board *board) {
    memset(board, 0, sizeof(Board));
    for (int i = 0; i < PLAYERS; i++) {
        board->pieces[i] = (1 << PIECES) - 1;
    }
}
