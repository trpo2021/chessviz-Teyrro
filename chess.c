#include <stdio.h>
#include <string.h>

#include <iostream>
using namespace std;

int const n = 8;
int const m = 9;

int main() {
  int i, j;
  char a[m][n] = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                  {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                  {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                  {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                  {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}};

  for (i = 0; i < m; i++) {
    if (i != n) {
      cout << n - i << " ";
    } else {
      cout << "  ";
    }
    for (j = 0; j < n; j++) {
      printf("%c ", a[i][j]);
    }
    printf("\n");
  }
}
