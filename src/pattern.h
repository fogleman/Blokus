#ifndef PATTERN_H
#define PATTERN_H

typedef struct {
    int piece;
    int rotation;
    int width;
    int height;
    char name[3];
    int data[7][7];
} Pattern;

extern int pattern_squares[PATTERNS][SQUARES][6];
extern Pattern patterns[];

void init_pattern_squares();

#endif
