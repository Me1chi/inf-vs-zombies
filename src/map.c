#include "raylib.h"
#include "plants.h"
#include "map.h"


int insert_plant(Plant plant, int row, int collum, char map[MAXMAPROWS][MAXMAPCOLLUMS]) {
    int success = 0;

    if (row >= MAXMAPROWS || collum >= MAXMAPCOLLUMS || row < 0 || collum < 0) {
        success = -1;
    } else {
        map[row][collum] = plant_code(plant);
        success = 1;
    }

    return success;
}
