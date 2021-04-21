#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

bool white_step(char table[8][8], int y, int x, int& swing)
{ // смена хода
    if (table[y][x] < 'Z') {
        swing++;
        return true;
    }
    return false;
}

bool black_step(char table[8][8], int y, int x, int& swing)
{
    if (table[y][x] > 'a') {
        swing--;
        return true;
    }

    return false;
}
