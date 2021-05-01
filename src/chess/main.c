#include "chesslib/constants.h"

#include "chesslib/Get_Move.h"
#include "chesslib/board.h"
#include "chesslib/checks.h"
#include "chesslib/white_black.h"

#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    bool input_file = true;
    int count = 0;
    setlocale(LC_ALL, "RUS");

    if (argc != 2) {
        printf(" ");
        input_file = false;
    }

    FILE* file;
    struct game* game;
    game = (games*)malloc(sizeof(games));
    (*game).swing = 0;

    create_board((*game).table);
    print_board((*game).table);

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("���������� ������� ����\n");
        fclose(file);
        input_file = false;
        exit(1);
    }

    while (true) {
        int index = 0;
        char input[str_size]; //������� ������

        if (input_file)
            fgets(input, str_size, file);

        if (input[0] >= 'A' && input[0] <= 'Z')
            index++;

        struct chess_info* chess[2];
        chess[0] = (info*)malloc(sizeof(info));
        chess[1] = (info*)malloc(sizeof(info));

        getMoves(input, chess[0], chess[1]);

        int x_dif = (abs(chess[0]->x_end - chess[0]->x)),
            y_dif = (abs(chess[0]->y_end - chess[0]->y));
        printf("Начальные коориданы: Y: %d, X: %d\n", chess[0]->y, chess[0]->x);
        printf("Конечные координаты: Y: %d, X: %d\n",
               chess[0]->y_end,
               chess[0]->x_end);
        printf("Разница координат: DY: %d, DX: %d\n", y_dif, x_dif);

        x_dif = (abs(chess[1]->x_end - chess[1]->x)),
        y_dif = (abs(chess[1]->y_end - chess[1]->y));
        printf("Начальные коориданы: Y: %d, X: %d\n", chess[1]->y, chess[1]->x);
        printf("Конечные координаты: Y: %d, X: %d\n",
               chess[1]->y_end,
               chess[1]->x_end);
        printf("Разница координат: DY: %d, DX: %d\n", y_dif, x_dif);

        for (int i = 0; i < 2; ++i) {
            count++;
            if (checks(game, chess[i]) == false) {
                return 1;
            } else {
                (*game).table[(*chess[i]).y_end][(*chess[i]).x_end]
                        = (*game).table[(*chess[i]).y][(*chess[i]).x];
                (*game).table[(*chess[i]).y][(*chess[i]).x] = ' ';
            }

            switch (i) {
            case 0: {
                printf("\nХод белых: \n %d. ", count);
                print_str((*chess[i]));
                break;
            }
            case 1: {
                printf("\nХод чёрных: \n %d. ", count);
                print_str((*chess[i]));
                break;
            }
            }

            (*game).swing = (((*game).swing + 1) % 2);

            print_board((*game).table);

            printf("\nPress Enter...\n");
            getchar();
        }
    }
}
