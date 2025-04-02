#include "plantsbar.h"
#include "raylib.h"
#include "buttons.h"
#include "plants.h"
#include <stdbool.h>
#include "game.h"
#include "structs.h"


char plant_button_logic();

void plant_button_draw(Button button, Plant plant, GameTextures textures) {

    Rectangle button_rect = get_button_rect(button);
    Rectangle beneath_rect = {0};
    Rectangle sun_rect = {0};
    Rectangle cost_rect = {0};

    // Rectangles definition
    beneath_rect = button_rect;

    beneath_rect.y += (1.0 - BUTTONTEXTBOXSIZE)*button_rect.y;
    beneath_rect.height = button_rect.height*BUTTONTEXTBOXSIZE;

    sun_rect = beneath_rect;

    sun_rect.width /= SUNBOXSIZE;

    cost_rect = beneath_rect;
    cost_rect.x += sun_rect.width;
    cost_rect.width -= sun_rect.width;

    // Drawing space


    // TESTING IT IS NOT DONE YET!!!!!!!!!!!!!!!!!!!!
    if(button.selected) {
        DrawRectangleRec(beneath_rect, GREEN);
        DrawRectangleRec(sun_rect, YELLOW);
        DrawRectangleRec(cost_rect, PINK);
    }
    else {
        DrawRectangleRec(beneath_rect, DARKGREEN);
        DrawRectangleRec(sun_rect, ORANGE);
        DrawRectangleRec(cost_rect, RED);
    }

}
