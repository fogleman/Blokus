#include <stdlib.h>
#include <string.h>
#include "eval.h"
#include "gen.h"
#include "search.h"
#include "util.h"

int monte(Board *board, int player, int depth) {
    Move moves[MOVES];
    for (int i = 0; i < depth; i++) {
        int count = gen_moves(board, moves);
        if (count == 0) {
            break;
        }
        do_move(board, &moves[rand_int(count)], NULL);
    }
    return evaluate(board, player);
}

int search(Board *board, double duration, Move *move) {
    Move moves[MOVES];
    int player = board->player;
    int count = gen_moves(board, moves);
    if (count == 0) {
        return 0;
    }
    int scores[count];
    memset(scores, 0, sizeof(scores));
    double start = now();
    Board temp;
    while (1) {
        for (int i = 0; i < count; i++) {
            board_copy(&temp, board);
            do_move(&temp, &moves[i], NULL);
            scores[i] += monte(&temp, player, 5);
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
