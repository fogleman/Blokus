#ifndef PLACEMENT_H
#define PLACEMENT_H

#include "bb.h"
#include "pattern.h"

typedef struct {
    bb filled;
    bb border;
    bb corner;
    char valid;
} Placement;

extern Placement placements[PATTERNS][SQUARES];

void init_placement(Pattern *pattern, int sq, Placement *placement);
void init_placements();

#endif
