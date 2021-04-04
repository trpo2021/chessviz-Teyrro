#include "chesslib/change_of_step.h"
#include "chesslib/board.h"
#include <iostream>
#include <stdio.h>
#include <clocale>
#include <string>

using namespace std;



int main(){ setlocale(LC_ALL, "RUS");
      char table[numbers_of_string][numbers_of_string] = {
      {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
   
   
   
   
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
      {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

  Output_Chessboard(table);


 int swing = 0; 
    int party = 1; const int size_str = 10;
    
    printf("\nХод белых: \n"); 
    printf("%d. ", party);
  
   do {	
    	
		int index = 0; 
      
      
      
        bool side;
    	string input; input.clear();
    	cin >> input;
    	
 
    	
    	printf("\n");
    	
    	
        int x, x_end, y, y_end;
        x = input[0+index] - 'a';
        x_end = input[3+index] - 'a';
        y = input[1+index] - '1';
        y_end = input[4+index] - '1';   
        y = 7 - y;
        y_end = 7 - y_end;

          if (border_check(input, size_str, x, x_end) == false){
              cerr << "Ошибка: Выход за границы";
            continue;
        }
        
        switch(swing){	case 0: 		side = white_step(table, y, x, swing); 		break;	case 1: 		side = black_step(table, y, x, swing); 
				break;
		}
		

		if(side == false){
			cerr << "Ошибка: сейчас ходит противоположная сторона \n";
			continue;
		}

      

        printf ("\nx: %d, y: %d, x_end: %d, y_end: %d\n", x, y, x_end, y_end); // stdout координат на доске


        table[y_end][x_end] = table[y][x];
        table[y][x] = ' ';
        
        Output_Chessboard(table);

        switch (swing) {
        	case 1:
        		printf("\nХод черных: \n");
        		printf("%d. ", party);
        		break;
        	case 0:
        		printf("\nХод белых: \n");
        		party++;
        		printf("%d. ", party);
        		break;
		}
		
    
	} while(true);
}