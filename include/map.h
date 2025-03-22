#pragma once
#include <raylib.h>
#include "plants.h"

#define MAXMAPROWS 3
#define MAXMAPCOLLUMS 4

void insert_plant(Plant plant, char map[MAXMAPROWS][MAXMAPCOLLUMS]);
