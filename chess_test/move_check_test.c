#include <ctest.h>
#include <stdlib.h>

#include <chesslib/constants.h>
#include <chesslib/figure.h>
#include <func_for_test.h>

CTEST(figure_check_suite, pawn_test)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 0;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'P';
    (*chess).y = 6;
    (*chess).x = 0;
    (*chess).y_end = 5;
    (*chess).x_end = 0;

    ASSERT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
}

CTEST(figure_check_suite, pawn_test2)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 0;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'P';
    (*chess).y = 6;
    (*chess).x = 0;
    (*chess).y_end = 4;
    (*chess).x_end = 0;

    ASSERT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
}

CTEST(figure_check_suite, pawn_test3)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 0;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'P';
    (*chess).y = 6;
    (*chess).x = 0;
    (*chess).y_end = 3;
    (*chess).x_end = 0;

    ASSERT_NOT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
}

CTEST(figure_check_suite, pawn_test4)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 0;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'P';
    (*chess).y = 6;
    (*chess).x = 0;
    (*chess).y_end = 7;
    (*chess).x_end = 0;

    ASSERT_NOT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
}

CTEST(figure_check_suite, pawn_test5)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 0;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'P';
    (*chess).y = 6;
    (*chess).x = 0;
    (*chess).y_end = 5;
    (*chess).x_end = 1;

    ASSERT_NOT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
    game = NULL;
    chess = NULL;
}

CTEST(figure_check_suite, pawn_test6)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 0;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'P';
    (*chess).y = 6;
    (*chess).x = 2;
    (*chess).y_end = 5;
    (*chess).x_end = 3;

    ASSERT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
    game = NULL;
    chess = NULL;
}

CTEST(figure_check_suite, pawn_test7)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 1;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'P';
    (*chess).y = 5;
    (*chess).x = 3;
    (*chess).y_end = 7;
    (*chess).x_end = 3;

    ASSERT_NOT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
    game = NULL;
    chess = NULL;
}

CTEST(figure_check_suite, pawn_test8)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 1;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'P';
    (*chess).y = 5;
    (*chess).x = 3;
    (*chess).y_end = 6;
    (*chess).x_end = 3;

    ASSERT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
    game = NULL;
    chess = NULL;
}

CTEST(figure_check_suite, knight_test)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 1;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'N';
    (*chess).y = 2;
    (*chess).x = 1;
    (*chess).y_end = 0;
    (*chess).x_end = 2;

    ASSERT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
    game = NULL;
    chess = NULL;
}

CTEST(figure_check_suite, knight_test2)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 1;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'N';
    (*chess).y = 2;
    (*chess).x = 1;
    (*chess).y_end = 1;
    (*chess).x_end = 3;

    ASSERT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
    game = NULL;
    chess = NULL;
}

CTEST(figure_check_suite, knight_test3)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 1;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'N';
    (*chess).y = 2;
    (*chess).x = 1;
    (*chess).y_end = 2;
    (*chess).x_end = 3;

    ASSERT_NOT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
    game = NULL;
    chess = NULL;
}

CTEST(figure_check_suite, king_test)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 0;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'K';
    (*chess).y = 6;
    (*chess).x = 5;
    (*chess).y_end = 7;
    (*chess).x_end = 6;

    ASSERT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
    game = NULL;
    chess = NULL;
}

CTEST(figure_check_suite, king_test2)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 0;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'K';
    (*chess).y = 6;
    (*chess).x = 5;
    (*chess).y_end = 5;
    (*chess).x_end = 5;

    ASSERT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
    game = NULL;
    chess = NULL;
}

CTEST(figure_check_suite, king_test3)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 0;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'K';
    (*chess).y = 6;
    (*chess).x = 5;
    (*chess).y_end = 6;
    (*chess).x_end = 4;

    ASSERT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
    game = NULL;
    chess = NULL;
}

CTEST(figure_check_suite, king_test4)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 0;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'K';
    (*chess).y = 6;
    (*chess).x = 5;
    (*chess).y_end = 6;
    (*chess).x_end = 3;

    ASSERT_NOT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
    game = NULL;
    chess = NULL;
}

CTEST(figure_check_suite, qeen_test)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 0;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'Q';
    (*chess).y = 2;
    (*chess).x = 4;
    (*chess).y_end = 3;
    (*chess).x_end = 3;

    ASSERT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
    game = NULL;
    chess = NULL;
}

CTEST(figure_check_suite, qeen_test2)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 0;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'Q';
    (*chess).y = 2;
    (*chess).x = 4;
    (*chess).y_end = 4;
    (*chess).x_end = 2;

    ASSERT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
    game = NULL;
    chess = NULL;
}

CTEST(figure_check_suite, qeen_test3)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 0;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'Q';
    (*chess).y = 2;
    (*chess).x = 4;
    (*chess).y_end = 5;
    (*chess).x_end = 1;

    ASSERT_NOT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
    game = NULL;
    chess = NULL;
}

CTEST(figure_check_suite, qeen_test4)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 0;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'Q';
    (*chess).y = 2;
    (*chess).x = 4;
    (*chess).y_end = 5;
    (*chess).x_end = 1;

    ASSERT_NOT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
    game = NULL;
    chess = NULL;
}

CTEST(figure_check_suite, qeen_test5)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 0;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'Q';
    (*chess).y = 2;
    (*chess).x = 4;
    (*chess).y_end = 2;
    (*chess).x_end = 3;

    ASSERT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
    game = NULL;
    chess = NULL;
}

CTEST(figure_check_suite, qeen_test6)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 0;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'Q';
    (*chess).y = 2;
    (*chess).x = 4;
    (*chess).y_end = 2;
    (*chess).x_end = 1;

    ASSERT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
    game = NULL;
    chess = NULL;
}

CTEST(figure_check_suite, qeen_test7)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 0;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'Q';
    (*chess).y = 2;
    (*chess).x = 4;
    (*chess).y_end = 2;
    (*chess).x_end = 0;

    ASSERT_NOT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
    game = NULL;
    chess = NULL;
}

CTEST(figure_check_suite, bishop_test)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 0;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'B';
    (*chess).y = 0;
    (*chess).x = 7;
    (*chess).y_end = 1;
    (*chess).x_end = 6;

    ASSERT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
    game = NULL;
    chess = NULL;
}

CTEST(figure_check_suite, rook_test)
{
    struct game* game;
    game = (games*)malloc(sizeof(games));

    (*game).swing = 0;

    struct chess_info* chess;
    chess = (info*)malloc(sizeof(info));

    create_chaos_board((*game).table);

    (*chess).figure = 'R';
    (*chess).y = 0;
    (*chess).x = 4;
    (*chess).y_end = 0;
    (*chess).x_end = 5;

    ASSERT_EQUAL(1, move_check(*game, *chess));
    free(game);
    free(chess);
    game = NULL;
    chess = NULL;
}