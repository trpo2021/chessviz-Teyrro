#include <ctest.h>
#include <stdlib.h>

#include <chesslib/constants.h>
#include <chesslib/figure.h>
#include <func_for_test.h>

CTEST(figure_check_suite, correct_figure_test)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'N';
    (*chess).y = 2;
    (*chess).x = 1;

    ASSERT_EQUAL(1, figure_check(*game, *chess));
    free(game);
    free(chess);
}

CTEST(figure_check_suite, correct_figure_test2)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'R';
    (*chess).y = 0;
    (*chess).x = 4;

    ASSERT_EQUAL(1, figure_check(*game, *chess));
    free(game);
    free(chess);
}

CTEST(figure_check_suite, uncorrect_figure_test)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'Q';
    (*chess).y = 2;
    (*chess).x = 1;

    ASSERT_NOT_EQUAL(1, figure_check(*game, *chess));
    free(game);
    free(chess);
}

CTEST(figure_check_suite, uncorrect_figure_test2)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'P';
    (*chess).y = 0;
    (*chess).x = 4;

    ASSERT_NOT_EQUAL(1, figure_check(*game, *chess));
    free(game);
    free(chess);
}
