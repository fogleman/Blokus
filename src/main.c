#include <stdio.h>
#include <string.h>
#include "bb.h"
#include "common.h"
#include "move.h"
#include "pattern.h"

int main(int argc, char *argv[]) {
    init_pattern_squares();
    init_moves();
    int n = 0;
    for (int p = 0; p < PATTERNS; p++) {
        for (int i = 0; i < CELLS; i++) {
            int sq = pattern_squares[p][60][i];
            if (sq < 0) {
                break;
            }
            Move *move = &pattern_moves[p][sq];
            bb_print(&move->filled);
            n++;
        }
    }
    printf("%d\n", n);
    return 0;
}
