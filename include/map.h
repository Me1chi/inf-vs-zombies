#pragma once
#include "structs.h"

int insert_plant(Plant plant, SmartMap *smart_map);

int insert_selected_plant(PlantManager *plant_manager, SmartMap *smart_map,
                          int *sun_stack);
