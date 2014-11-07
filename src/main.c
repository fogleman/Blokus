#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "board.h"
#include "common.h"
#include "gen.h"
#include "placement.h"
#include "pattern.h"
#include "util.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));
    init_pattern_squares();
    init_placements();
    int games = 0;
    double start = now();
    while (1) {
        Board board;
        board_clear(&board);
        Move moves[MOVES];
        while (1) {
            int count = gen_moves(&board, moves);
            if (count == 0) {
                break;
            }
            int index = rand_int(count);
            do_move(&board, &moves[index], NULL);
            // board_print(&board);
        }
        games++;
        double elapsed = now() - start;
        double gps = games / elapsed;
        if (games % 1000 == 0) {
            printf("%d: %f (%f games per second)\n", games, elapsed, gps);
        }
    }
    return 0;
}
