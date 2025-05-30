#pragma once
#include "raylib.h"
#include "structs.h"

void draw_centralized_text(Button button, float text_scale);

void button_draw(Button button, Color color, float text_scale);

void button_draw_texture(Button button, float text_scale);

Rectangle get_button_rect(Button button);

void navigate_arrow_map(SmartMap* smart_map, int map_length, int map_heigth);
