#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int const n = 8;

int main()
{
    int i, j;
    char a[9][8] = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                	{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}};

    for (i = 0; i < 9; i++) {
    	if (i != 8)
    	{
    	cout << 8-i << " ";
    	}
    	else
    	{
			cout << "  ";
        }
        for (j = 0; j < n; j++) {
          printf("%c ", a[i][j]);
        }
        printf("\n");
    }
}
