#pragma once
#include "raylib.h"
#include "plants.h"
#include "game.h"
#include "structs.h"

int insert_plant(Plant plant, SmartMap *smart_map);

int insert_selected_plant(PlantManager *plant_manager, SmartMap *smart_map);
