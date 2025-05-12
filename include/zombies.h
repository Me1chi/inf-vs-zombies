#pragma once 
#include "structs.h"
#include "game.h"

void zombie_spawn(int total_zombies, Zombie *zombies);

void zombies_walk(int total_zombies, Zombie *zombies);

void zombies_bite(SmartMap *smart_map, Zombie *zombies, int total_zombies);

void zombies_damage_take(ProjectileArray *projectiles, Zombie *zombies, int total_zombies);

void zombies_draw(GameTextures textures, Zombie *zombies, int total_zombies);
