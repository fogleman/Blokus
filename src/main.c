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
    //     board_clear(&board);
    //     while (1) {
    //         // Move moves[MOVES];
    //         // int count = gen_moves(&board, moves);
    //         // if (count == 0) {
    //         //     break;
    //         // }
    //         Move move;
    //         if (!gen_random_move(&board, &move)) {
    //             break;
    //         }
    //         // printf("hi\n");
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
    while (1) {
        Move move;
        if (!search(&board, 1, &move)) {
            break;
        }
        do_move(&board, &move, NULL);
        board_print(&board);
    }
    for (int i = 0; i < PLAYERS; i++) {
        printf("%d: %d\n", i + 1, 89 - board.score[i]);
    }
    return 0;
}
