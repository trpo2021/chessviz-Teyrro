#pragma once
#include <stdbool.h>

bool white_step(struct game* game, struct chess_info chess);
bool black_step(struct game* game, struct chess_info chess);
bool friendly_fire_(struct game game, struct chess_info chess);
bool white_black_step(struct chess_info chess, struct game* game);