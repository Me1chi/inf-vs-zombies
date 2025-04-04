#include "plantsbar.h"
#include "raylib.h"
#include "buttons.h"
#include "plants.h"
#include <stdbool.h>
#include <stdio.h>
#include "game.h"
#include "structs.h"


char plant_button_logic();

void plant_button_draw(Button button, Plant plant, GameTextures textures) {

    // Complementary buttons definition
    Button beneath_button = button;
    Button sun_button = {0};
    Button cost_button = {0};

    beneath_button.position.y += (1.0 - BUTTONTEXTBOXSIZE)*button.size.y - SMALLBLANKSPACE/4.0;
    beneath_button.size.y = button.size.y*BUTTONTEXTBOXSIZE;

    sun_button = beneath_button;
    sun_button.size.x *= SUNBOXSIZE;

    cost_button = beneath_button;
    cost_button.position.x += sun_button.size.x;
    cost_button.size.x -= sun_button.size.x;
    cost_button.text_color = BLACK;

    sprintf(cost_button.text, "%d", plant.cost);

    // Plant positioning

    Rectangle plant_rect = {
        button.position.x,
        button.position.y,
        button.size.x*BUTTONINNERSPACESCALE,
        button.size.y*(1-BUTTONTEXTBOXSIZE),
    };

    Vector2 origin = {0, 0};

    Rectangle rect_source = {
            0.0f,
            0.0f,
            plant.texture.width,
            plant.texture.height,
        };

    // Textures attribution
    sun_button.texture = textures.sun;
    cost_button.texture = textures.button_text;

    // Drawing space
    button_draw_texture(button, BUTTONTEXTBOXSIZE);
    button_draw_texture(sun_button, BUTTONTEXTBOXSIZE);
    button_draw_texture(cost_button, BUTTONTEXTBOXSIZE*3.5);

    if (button.selected)
        DrawTexturePro(plant.texture, rect_source, plant_rect, origin, 0.0, GRAY);
    else
        DrawTexturePro(plant.texture, rect_source, plant_rect, origin, 0.0, WHITE);
}

void sun_stack_draw(Button button) {

    button_draw_texture(button, 0.35);

}
