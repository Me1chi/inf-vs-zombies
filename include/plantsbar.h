#pragma once
#include "structs.h"

void plant_button_draw(Button button, Plant plant, GameTextures textures);

void plant_button_draw_manager(PlantManager plant_manager,
                               GameTextures textures, int index);

void select_plant_input(PlantManager *plant_manager, int sun_stack);

void sun_stack_draw(Button button);
