#pragma once
#include <stdbool.h>

extern const int str_num;
extern const int str_size;

typedef struct chess_info {
	int x, x_end, y, y_end;
	char figure;
	char input[5];
	int index;
	char move_type;
	bool friendly_fire;


	

} info;

typedef struct game {
	char table[8][8];
	int swing;
} games;
