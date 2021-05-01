#include "constants.h"

#include "chessmen.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int abs(int);
bool figure_check(struct game game, struct chess_info chess)
{
    if ((chess.figure + 32) == game.table[chess.y][chess.x]
        || chess.figure == game.table[chess.y][chess.x])
        return true;
    return false;
}

bool move_check(struct game game, struct chess_info chess)
{
    char fig = (game.table[chess.y][chess.x] - (game.swing * ('a' - 'A')));
    int dx, dy;
    dx = chess.x_end - chess.x;
    dy = chess.y_end - chess.y;
    int x_dif = abs(dx);
    int y_dif = abs(dy);

    switch (fig) {
		
    case 'N': {
        if (x_dif == 2 && y_dif == 1)
            return true;
        if (x_dif == 1 && y_dif == 2)
            return true;
    }
        return false;

    case 'B': {
        if (bishop(game, chess, dx, dy) == true)
            return true;
    }
        return false;

    case 'R': {
        if (rook(game, chess, dx, dy) == true)
            return true;
    }
        return false;

    case 'P': {
        if (dy != 0)
            dy = dy / abs(dy);

        if (!(dy == -1 + (game.swing * (2))))
            return false;

        if (y_dif == 1 && (x_dif == 1)
            && (game.table[chess.y_end][chess.x_end] != ' '))
            return true;

        if (chess.x == chess.x_end) {
            if (chess.y == 6 - game.swing * (5)) {
                if (y_dif == 2 && game.table[chess.y_end][chess.x_end] == ' '
                    && game.table[(chess.y_end + (1 + (game.swing * (-2))))]
                                 [chess.x_end]
                            == ' ') {
                    return true;
                }
            }

            if (y_dif == 1 && game.table[chess.y_end][chess.x_end] == ' ')
                return true;
            return false;
        }
    }
        return false;

    case 'Q': {
        if (bishop(game, chess, dx, dy) == true)
            return true;
        if (rook(game, chess, dx, dy) == true)
            return true;
    }
        return false;

    case 'K': {
        if (x_dif == 1 && y_dif == 0)
            return true;
        if (x_dif == 0 && y_dif == 1)
            return true;
        if (x_dif == 1 && y_dif == 1)
            return true;
    }
        return false;
    }
    return false;
}
