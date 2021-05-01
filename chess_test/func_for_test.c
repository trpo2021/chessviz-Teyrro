#include "chesslib/constants.h"

void create_chaos_board(char table[str_num][str_num])
{
    char tmp[str_num][str_num];

    for (int i = 0; i < str_num; i++)
        for (int j = 0; j < str_num; j++)
            tmp[i][j] = ' ';

    tmp[0][2] = 'P';
    tmp[0][4] = 'R';
    tmp[0][7] = 'B';
    tmp[2][1] = 'n';
    tmp[2][4] = 'Q';
    tmp[4][2] = 'p';
    tmp[5][2] = 'p';
    tmp[5][3] = 'p';
    tmp[6][0] = 'P';
    tmp[6][2] = 'P';
    tmp[6][4] = 'p';
    tmp[6][5] = 'K';
    tmp[7][2] = 'p';

    for (int i = 0; i < str_num; i++) {
        for (int j = 0; j < str_num; j++) {
            table[i][j] = tmp[i][j];
        }
    }
}