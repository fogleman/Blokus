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

    // int games = 0;
    // double start = now();
    // while (1) {
    //     Board board;
    //     Move move;
    //     board_clear(&board);
    //     while (gen_random_move(&board, &move)) {
    //         do_move(&board, &move, NULL);
    //     }
    //     games++;
    //     if (games % 1000 == 0) {
    //         double gps = games / (now() - start);
    //         printf("%d, %f\n", games, gps);
    //     }
    // }

    Board board;
    board_clear(&board);
    int passes = 0;
    while (1) {
        Move move;
        if (search(&board, 0.5, &move)) {
            do_move(&board, &move, NULL);
            passes = 0;
        }
        else {
            do_move(&board, NULL, NULL);
            passes++;
        }
        board_print(&board);
        if (passes >= PLAYERS) {
            break;
        }
    }
    for (int i = 0; i < PLAYERS; i++) {
        printf("%d: %d\n", i + 1, 89 - board.score[i]);
    }
    return 0;
}
