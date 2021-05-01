#include "constants.h"
#include "white_black.h"
#include <stdio.h>

void create_board(char table[str_num][str_num])
{
    char tmp[str_num][str_num];

    for (int i = 0; i < str_num; i++)
        for (int j = 0; j < str_num; j++)
            tmp[i][j] = ' ';

    for (int i = 0; i < 8; ++i) {
        tmp[1][i] = 'p';
        tmp[6][i] = 'P';
    }
    tmp[0][0] = 'r';
    tmp[0][7] = 'r';
    tmp[7][0] = 'R';
    tmp[7][7] = 'R';
    tmp[0][1] = 'n';
    tmp[0][6] = 'n';
    tmp[7][1] = 'N';
    tmp[7][6] = 'N';
    tmp[0][2] = 'b';
    tmp[0][5] = 'b';
    tmp[7][2] = 'B';
    tmp[7][5] = 'B';
    tmp[0][3] = 'q';
    tmp[7][3] = 'Q';
    tmp[0][4] = 'k';
    tmp[7][4] = 'K';

    for (int i = 0; i < str_num; i++) {
        for (int j = 0; j < str_num; j++) {
            table[i][j] = tmp[i][j];
        }
    }
}

void print_str(struct chess_info chess)
{
    for (int i = 0; i < 5; i++) {
        printf("%c", chess.input[i]);
    }
}

void print_board(char table[str_num][str_num])
{
    int i, j, num = 8;

    printf("\n   A B C D E F G H\n\n");

    for (i = 0; i < str_num; i++) {
        printf("%d  ", num);
        for (j = 0; j < str_num; j++) {
            printf("%c ", table[i][j]);
        }
        printf("  %d\n", num);
        num--;
    }
    printf("\n   A B C D E F G H\n");
}

bool border_check(struct chess_info chess)
{
    if (((chess.y >= 0 && chess.y <= 7) && (chess.x >= 0 && chess.x <= 7))
        && ((chess.y_end >= 0 && chess.y_end <= 7)
            && (chess.x_end >= 0 && chess.x_end <= 7))) {
        return true;
    }
    return false;
}

bool type_check(struct game game, struct chess_info* chess)
{
    if ((*chess).move_type == '-'
        && game.table[(*chess).y_end][(*chess).x_end] == ' '
        && game.table[(*chess).y][(*chess).x] != ' ') {
        return true;
    }
    if ((*chess).move_type == 'x'
        && game.table[(*chess).y_end][(*chess).x_end] != ' '
        && game.table[(*chess).y][(*chess).x] != ' ') {
        (*chess).friendly_fire = friendly_fire_(game, *chess);

        return true;
    }

    return false;
}

// char tmp[str_num][str_num]  =
// 			{{"rnbqkbnr"},
//             {"pppppppp"},
//             {"        "},
//             {"        "},
//             {"        "},
//             {"        "},
//             {"PPPPPPPP"},
//             {"RNBQKBNR"}};

// char tmp[str_num][str_num]  =
// 			{{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
//             {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
//             {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
//             {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
//             {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
//             {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
//             {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
//             {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
