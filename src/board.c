#include <stdio.h>
#include <string.h>
#include "board.h"

void board_clear(Board *board) {
    memset(board, 0, sizeof(Board));
    for (int i = 0; i < PLAYERS; i++) {
        board->pieces[i] = (1 << PIECES) - 1;
    }
    BB_SET(board->corner[0], SQ(4, 4));
    BB_SET(board->corner[1], SQ(9, 9));
}

void board_copy(Board *dst, Board *src) {
    memcpy(dst, src, sizeof(Board));
}

void board_print(Board *board) {
    char *codes = "xo";
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int blank = 1;
            for (int i = 0; i < PLAYERS; i++) {
                if (BIT_TEST(board->filled[i].data, SQ(x, y))) {
                    printf("%c ", codes[i % 2]);
                    blank = 0;
                    break;
                }
            }
            if (blank) {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}
