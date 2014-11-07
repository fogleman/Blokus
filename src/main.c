#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "board.h"
#include "common.h"
#include "gen.h"
#include "placement.h"
#include "pattern.h"
#include "search.h"
#include "util.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));
    init_pattern_squares();
    init_placements();
    Board board;
    board_clear(&board);
    while (1) {
        Move move;
        if (!search(&board, 2, &move)) {
            break;
        }
        do_move(&board, &move, NULL);
        board_print(&board);
    }
    return 0;
}
