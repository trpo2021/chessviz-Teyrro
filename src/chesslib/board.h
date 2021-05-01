#pragma once
#include <stdbool.h>

void create_board(char table[str_num][str_num]);
void print_str(struct chess_info chess);
void print_board(char table[str_num][str_num]);
bool border_check(struct chess_info chess);
bool type_check(struct game game, struct chess_info* chess);
