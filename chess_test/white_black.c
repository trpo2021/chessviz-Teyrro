#include "chesslib/constants.h"

#include "chesslib/board.h"
#include "chesslib/white_black.h"
#include "func_for_test.h"

#include <ctest.h>
#include <stdbool.h>
#include <stdlib.h>

CTEST(queue_suite, white_and_black_step_1)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    game->swing = 0;
    create_chaos_board(game->table);
    struct chess_info* chess[2];

    chess[0] = (info*)malloc(sizeof(info));

    chess[0]->figure = game->table[2][4];
    chess[0]->x = 4;
    chess[0]->y = 2;
    chess[0]->x_end = 2; // 4 2  && 2 1N
    chess[0]->y_end = 4;
    chess[0]->move_type = '-';

    chess[1] = (info*)malloc(sizeof(info));

    chess[1]->figure = game->table[2][4];
    chess[1]->x = 4;
    chess[1]->y = 2;
    chess[1]->x_end = 2; // 4 2  && 2 1N
    chess[1]->y_end = 4;
    chess[1]->move_type = '-';

    for (int i = 0; i < 2; i++) {
        ASSERT_EQUAL(1, white_black_step(*chess[i], game));
        free(chess[i]);
        chess[i] = NULL;
    }

    free(game);
    game = NULL;
}