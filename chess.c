#include <stdio.h>
#include <string.h>

int const n = 8;

int main()
{
    int i, j;
    char a[8][8]
            = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }
}