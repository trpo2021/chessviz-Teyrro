#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define numbers_of_string 9
#define numbers_of_column 8


int main() {
  int i, j;
  char a[numbers_of_string][numbers_of_string] = {
      {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
      {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
      {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}};

  for (i = 0; i < numbers_of_string; i++) {
    if (i != numbers_of_column) {
      cout << numbers_of_column - i << " ";
    } else {
      cout << "  ";
    }
    for (j = 0; j < numbers_of_column; j++) {
      printf("%c ", a[i][j]);
    }
    printf("\n");
  }
}
