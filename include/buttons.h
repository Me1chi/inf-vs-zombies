#pragma once
#include "raylib.h"
#include "structs.h"

void draw_centralized_text(Button button);

int button_logic(Button button);

void button_draw(Button button, Color color);

void button_draw_texture(Button button);

Rectangle get_button_rect(Button button);
