#include "constants.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int abs(int);
bool bishop(struct game game, struct chess_info chess, int dx, int dy)
{
    int i, j;

    if (abs(dx) != abs(dy))
        return false;

    dx /= abs(dx);
    dy /= abs(dy);

    for (i = chess.x + dx, j = chess.y + dy; i != chess.x_end;
         i += dx, j += dy) {
        if (game.table[j][i] != ' ')
            return false;
    }
    return true;
}

bool rook(struct game game, struct chess_info chess, int dx, int dy)
{
    int i, j;

    if (dx != 0 && dy == 0) {
        dx /= abs(dx);
        for (i = chess.x + dx, j = chess.y + dy; i != chess.x_end; i += dx) {
            if (game.table[j][i] != ' ')
                return false;
        }
        return true;
    }

    if (dy != 0 && dx == 0) {
        dy /= abs(dy);
        for (i = chess.x + dx, j = chess.y + dy; j != chess.y_end; j += dy) {
            if (game.table[j][i] != ' ')
                return false;
        }
        return true;
    }
    return false;
}
