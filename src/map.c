#include "raylib.h"
#include "plants.h"
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
