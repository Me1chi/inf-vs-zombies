#include <raylib.h>
#include "plants.h"
#include "map.h"


void insert_plant(Plant plant, char map[MAXMAPROWS][MAXMAPCOLLUMS]) {
    int row = (int)(plant.position.x);
    int collum = (int)(plant.position.y);

    map[row][collum] = plant_code(plant);
}
