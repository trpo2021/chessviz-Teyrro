#include <stdio.h>
#include <iostream>
using namespace std;

#define numbers_of_string 8
#define numbers_of_column 8

void Output_Chessboard(char A[numbers_of_string][numbers_of_column]){
  int i, j;
  for (i = 0; i < numbers_of_string; i++) {
    if (i != numbers_of_column) {
      cout << numbers_of_column - i << " ";
    } else {
      cout << "  ";
    }
    for (j = 0; j < numbers_of_column; j++) {
      printf("%c ", A[i][j]);
    }
    printf("\n");
  }
  printf("  A B C D E F G H\n");
}

bool border_check(string input, const int size_str){
	int border_check = 0; // если значение равно 4, то мы не вышли за границу
		for(int i=0; i < size_str; i++) {
    		if ((input[i] >= 'a' && input[i] <= 'h') || (input[i] >= '0' && input[i] <= '9')){ 
    			border_check++;	
			}
		}
	if(border_check != 4){
		return false;
	}
	return true;
}

bool white_step(char table[8][8], int y, int x, int &swing){ //�������� �� ������� � ����� ����
	if (table[y][x] < 'Z'){
		swing++;
		return true;	
	}
	return false;
}

bool black_step(char table[8][8], int y, int x, int &swing){ //�������� �� ������� � ����� ����
	if(table[y][x] > 'a'){
		swing--;
		return true;
	}
	
	return false;
}

