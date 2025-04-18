#pragma once
#include "game.h"
#include "structs.h"

void draw_game_grid(SmartMap smart_map, GameTextures textures, Plant* plants);

SmartMap initialize_smart_map(int size_x, int size_y);
