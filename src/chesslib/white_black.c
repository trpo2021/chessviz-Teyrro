#include "constants.h"
#include <stdbool.h>

bool white_step(struct game* game, struct chess_info chess)
{ //�������� �� ������� � ����� ����
    if ((*game).table[chess.y][chess.x] < 'Z') {
        return true;
    }
    return false;
}

bool black_step(struct game* game, struct chess_info chess)
{ //�������� �� ������� � ����� ����
    if ((*game).table[chess.y][chess.x] > 'a') {
        return true;
    }

    return false;
}

bool friendly_fire_(struct game game, struct chess_info chess)
{
    if (game.table[chess.y_end][chess.x_end] >= 'a' && game.swing == 0)
        return true;
    if (game.table[chess.y_end][chess.x_end] < 'Z' && game.swing == 1)
        return true;
    return false;
}

bool white_black_step(struct chess_info chess, struct game* game)
{
    switch ((*game).swing) {
    case 0:
        return white_step(game, chess);
    case 1:
        return black_step(game, chess);
    }
    return false;
}
