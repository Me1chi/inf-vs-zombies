#include "raylib.h"
#include "plants.h"
#include "map.h"


void insert_plant(Plant plant, int row, int collum, char map[MAXMAPROWS][MAXMAPCOLLUMS]) {
    map[row][collum] = plant_code(plant);
}
