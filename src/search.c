#include <stdlib.h>
#include <string.h>
#include "eval.h"
#include "gen.h"
#include "search.h"
#include "util.h"

int monte(Board *board, int player, int depth) {
    Move move;
    int passes = 0;
    for (int i = 0; i < depth; i++) {
        if (gen_random_move(board, &move)) {
            do_move(board, &move, NULL);
            passes = 0;
        }
        else {
            do_move(board, NULL, NULL);
            passes++;
            if (passes == PLAYERS) {
                break;
            }
        }
    }
    return evaluate(board, player);
}

int search(Board *board, double duration, Move *move) {
    Move moves[MOVES];
    int scores[MOVES] = {0};
    int count = gen_moves(board, moves);
    if (count == 0) {
        return 0;
    }
    double start = now();
    while (1) {
        for (int i = 0; i < count; i++) {
            Board temp;
            board_copy(&temp, board);
            do_move(&temp, &moves[i], NULL);
            scores[i] += monte(&temp, board->player, 15);
        }
        if (now() - start > duration) {
            break;
        }
    }
    int best = scores[0] - 1;
    for (int i = 0; i < count; i++) {
        if (scores[i] > best) {
            best = scores[i];
            memcpy(move, &moves[i], sizeof(Move));
        }
    }
    return 1;
}
