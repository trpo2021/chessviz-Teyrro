#pragma once
#include <string>
#include <iostream>

using namespace std;
#define numbers_of_string 8
#define nubmers_of_column 8

void Output_Chessboard(char table[8][8]);
bool border_check(string input, const int size_str, int x, int x_end);