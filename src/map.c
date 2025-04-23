#include "game.h"
#include "raylib.h"
#include "plants.h"
#include "structs.h"
#include "map.h"


int insert_plant(Plant plant, SmartMap *smart_map) {
    int success = 0;
    int row = 0;
    int col = 0;

    row = smart_map->selected_row;
    col = smart_map->selected_col;

    if (row >= MAXMAPROWS || col >= MAXMAPCOLLUMS || row < 0 || col < 0) {
        success = -1;
    } else {
        smart_map->map[row][col] = plant_code(plant);
        success = 1;
    }

    return success;
}

int find_selected_plant(PlantManager plant_manager) {

    int selected_plant_index = -1;

    for (int i = 0; i < HOWMANYPLANTS; i++) {
        if (plant_manager.plants_bar[i].selected) {
            selected_plant_index = i;
        }
    }

    return selected_plant_index;
}

int insert_selected_plant(PlantManager *plant_manager, SmartMap *smart_map) {
    int index = 0;
    Plant selected_plant = {0};

    index = find_selected_plant(*plant_manager);

    if (index == -1) {
        return -1;
    } else {
        selected_plant = plant_manager->plants[index];
    }

    insert_plant(selected_plant, smart_map);

    plant_manager->plants_bar[index].selected = false;
    
    return 1;
}
