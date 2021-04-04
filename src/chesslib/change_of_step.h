#pragma once
#include <string>
using namespace std;

bool white_step(char table[8][8], int y, int x, int& swing);
bool black_step(char table[8][8], int y, int x, int& swing);