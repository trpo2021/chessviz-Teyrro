#include "constants.h"

#include "board.h"
#include "figure.h"
#include "white_black.h"

#include <stdbool.h>
#include <stdio.h>

bool checks(struct game* game, struct chess_info* chess)
{
    if (border_check((*chess)) == false) {
        printf("\nОшибка: Выход за границы\n\n");
        return false;
    }

    if (white_black_step(*chess, game) == false) {
        printf("\nОшибка: сейчас ходит противоположная сторона\n");
        return false;
    }

    if (figure_check(*game, *chess) == false) {
        printf("\nОшибка: Фигуры не соответствуют\n\n");
        return false;
    }

    if (type_check(*game, chess) == false) {
        printf("\nОшибка: Тип хода не соответствует действию\n\n");
        return false;
    }

    if ((*chess).friendly_fire == false) {
        printf("\nОшибка: Вы не можете съесть своих\n\n");
        return false;
    }

    if (move_check(*game, *chess) == false) {
        printf("\nОшибка: Эта фигура так не ходит, либо на её пути "
               "препятствие\n\n");
        return false;
    }
    return true;
}