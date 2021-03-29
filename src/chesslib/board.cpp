#include <string>
using namespace std;

bool border_check(string input, const int size_str){
	int border_check = 0; // если значение равно 4, то мы не вышли за границу
	for(int i=0; i < size_str; i++) {
    	if ((input[i] >= 'a' && input[i] <= 'h') || (input[i] >= '0' && input[i] <= '8')){ 
    		border_check++;	
		}
	}
	if(border_check != 4){
		return false;
	}
	return true;
}