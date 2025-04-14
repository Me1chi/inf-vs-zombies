#pragma once
#include "game.h"
#include "map.h"
#include "raylib.h"
#include <structs.h>

char plant_code(Plant plant);

int parse_plant(char code, Plant* array, Plant* plant);

void update_projectiles(ProjectileArray* projectiles);

void draw_projectiles(ProjectileArray projectiles, GameTextures textures);

void all_plants_shoot(Plant* plants, ProjectileArray* proj_arr);

void plant_shoot(Plant plant, ProjectileArray* projectiles);
