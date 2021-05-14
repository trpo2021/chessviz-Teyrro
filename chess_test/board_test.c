#include "chesslib/constants.h"

#include "chesslib/board.h"
#include "chesslib/white_black.h"
#include "func_for_test.h"

#include <ctest.h>
#include <stdbool.h>
#include <stdlib.h>

CTEST(border_suite, border_checks_1)
{
    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));
    chess->x = 2;
    chess->y = 3;
    chess->x_end = 5;
    chess->y_end = 4;
    ASSERT_EQUAL(1, border_check(*chess));
    free(chess);
    chess = NULL;
}

CTEST(border_suite, border_checks_2)
{
    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));
    chess->x = -1;
    chess->y = 2;
    chess->x_end = 5;
    chess->y_end = 4;
    ASSERT_NOT_EQUAL(1, border_check(*chess));
    free(chess);
    chess = NULL;
}

CTEST(border_suite, border_checks_3)
{
    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));
    chess->x = 2;
    chess->y = 9;
    chess->x_end = 2;
    chess->y_end = 4;
    ASSERT_NOT_EQUAL(1, border_check(*chess));
    free(chess);
    chess = NULL;
}

CTEST(border_suite, border_checks_4)
{
    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));
    chess->x = 2;
    chess->y = 3;
    chess->x_end = -5;
    chess->y_end = -4;
    ASSERT_NOT_EQUAL(1, border_check(*chess));
    free(chess);
    chess = NULL;
}

CTEST(border_suite, border_checks_5)
{
    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));
    chess->x = 2;
    chess->y = 3;
    chess->x_end = 5;
    chess->y_end = 24;
    ASSERT_NOT_EQUAL(1, border_check(*chess));
    free(chess);
    chess = NULL;
}

CTEST(type_check_suite, type_checks_1)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    create_chaos_board(game->table);
    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    chess->figure = game->table[2][4];
    chess->x = 4;
    chess->y = 2;
    chess->x_end = 1; // 2 4n && 1 2p
    chess->y_end = 2;
    chess->move_type = 'x';

    ASSERT_EQUAL(1, type_check(*game, chess));
    free(chess);
    free(game);
    chess = NULL;
    game = NULL;
}

CTEST(type_check_suite, type_checks_2)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    create_chaos_board(game->table);
    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    chess->figure = game->table[2][4];
    chess->x = 4;
    chess->y = 2;
    chess->x_end = 0; // 4 2  && 2 1N
    chess->y_end = 2;
    chess->move_type = 'x';

    ASSERT_NOT_EQUAL(1, type_check(*game, chess));
    free(chess);
    free(game);
    chess = NULL;
    game = NULL;
}

CTEST(type_check_suite, type_checks_3)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    create_chaos_board(game->table);
    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    chess->figure = game->table[2][4];
    chess->x = 4;
    chess->y = 2;
    chess->x_end = 3; // 2 4n && 1 2p
    chess->y_end = 3;
    chess->move_type = '-';

    ASSERT_EQUAL(1, type_check(*game, chess));
    free(chess);
    free(game);
    chess = NULL;
    game = NULL;
}

CTEST(type_check_suite, type_checks_4)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    create_chaos_board(game->table);
    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    chess->figure = game->table[2][4];
    chess->x = 4;
    chess->y = 2;
    chess->x_end = 2; // 4 2  && 2 1N
    chess->y_end = 4;
    chess->move_type = '-';

    ASSERT_NOT_EQUAL(1, type_check(*game, chess));
    free(chess);
    free(game);
    chess = NULL;
    game = NULL;
}

CTEST(type_check_suite, type_checks_5)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    create_chaos_board(game->table);
    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    chess->figure = game->table[2][4];
    chess->x = 4;
    chess->y = 2;
    chess->x_end = 4; // 4 2  && 2 1N
    chess->y_end = 0;
    chess->move_type = '-';

    ASSERT_NOT_EQUAL(1, type_check(*game, chess));
    free(chess);
    free(game);
    chess = NULL;
    game = NULL;
}
