// Shared types and helpers for the top K elements problems.
#ifndef DSAPATTERNS_TOPKELEMENTS_SHARED_H
#define DSAPATTERNS_TOPKELEMENTS_SHARED_H

typedef struct
{
    int x;
    int y;
} Point;

static inline int dist_from_origin
(
    Point p
)
{
    // ignoring sqrt
    return p.x * p.x + p.y * p.y;
}

#endif
