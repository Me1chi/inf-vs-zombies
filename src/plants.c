#include "plants.h"
#include "clock.h"
#include "game.h"
#include "raylib.h"
#include "structs.h"

#define PROJECTILESPEED  0.25 //it means 4 tiles/s

char plant_code(Plant plant) {
    return plant.name[0];
}

int parse_plant(char code, Plant* array, Plant* plant) {
    for (int i = 0; i < HOWMANYPLANTS; i++) {
        if (array[i].name[0] == code) {
            *plant = array[i];
            return 1;
        }
    }
    return -1;

}

void plant_shoot(Plant plant, ProjectileArray* projectiles) {
        Projectile current_proj;
        int direction = 1;

        if (projectiles->counter >= MAXPROJECTILES)
            projectiles->counter = 0;

        current_proj = projectiles->array[projectiles->counter];

        //modify the projectile features

        projectiles->array[projectiles->counter] = current_proj;

        projectiles->counter++;
}

void all_plants_shoot(Plant* plants, ProjectileArray* proj_arr) {
    Plant plant;

    for (int i = 0; i < HOWMANYPLANTS; i++) {
        plant = plants[i];

        static float timer_accum = 0;

        int tick = 0;

        if (timer_accum >= plant.rate) {
            timer_accum = 0;
            tick = 1;
        } else {
            timer_accum += GetFrameTime();
        }

        if (tick == 1)
            plant_shoot(plant, proj_arr);
    }
}

void update_projectiles(ProjectileArray* projectiles) {
    for (int i = 0; i < MAXPROJECTILES; i++) {
        projectiles->array[i].position.x += PROJECTILESPEED;
    }
}

void draw_projectiles(ProjectileArray projectiles, GameTextures textures) {
    Projectile proj;

    for (int i = 0; i < MAXPROJECTILES; i++) {
        proj = projectiles.array[i];

        DrawTextureEx(textures.pea_projectile, proj.position, 0, 1, proj.filter);
    }
}
