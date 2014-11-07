#ifndef PATTERN_H
#define PATTERN_H

typedef struct {
    int piece;
    int rotation;
    int width;
    int height;
    int cells;
    char name[4];
    int data[7][7];
} Pattern;

extern int pattern_squares[PATTERNS][SQUARES][CELLS];
extern Pattern patterns[PATTERNS];

void init_pattern_squares();

#endif
