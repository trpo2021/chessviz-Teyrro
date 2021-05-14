#include "constants.h"

void getMove(char* s, info* m)
{
    char r[20];
    int length = 0;
    for (int i = 0; i < 20; i++) {
        if (s[i] == ' ')
            continue;

        r[length++] = s[i];
        if (r[length - 1] == 0 || r[length - 1] == '\n') {
            break;
        }
    }
    if (length == 6) {
        (*m).figure = 'P';
        for (int i = 0; i < length; ++i)
            (*m).input[i] = r[i];
    } else {
        (*m).figure = r[0];
        length--;
        for (int i = 0; i < length; ++i)
            (*m).input[i] = r[i + 1];
    }
    (*m).move_type = (*m).input[2];
    (*m).x = (*m).input[0] - 'a';
    (*m).x_end = (*m).input[3] - 'a';
    (*m).y = 7 - (*m).input[1] + '1';
    (*m).y_end = 7 - (*m).input[4] + '1';
    (*m).friendly_fire = true;
}

void getMoves(char* s, struct chess_info* m1, struct chess_info* m2)
{
    char in[2][20];

    for (int i = 0, k = -1, t = 0, f = 0; k < 2 && i < 20; ++i) {
        if (s[i] == '.') {
            k++;
            continue;
        }
        if (k < 0)
            continue;
        in[k][t++] = s[i];
        if ((s[i] >= 'a' && s[i] <= 'h') || (s[i] >= '1' && s[i] <= '8'))
            f++;
        if (f >= 4) {
            in[k][t] = 0;
            t = 0;
            k++;
            f = 0;
        }
    }

    getMove(in[0], m1);
    getMove(in[1], m2);
}
