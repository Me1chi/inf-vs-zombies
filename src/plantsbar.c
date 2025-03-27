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

    Vector2 mouse_pointer = GetMousePosition();

    bool hovering = false;







}
