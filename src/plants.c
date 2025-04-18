#include "plants.h"
#include "clock.h"
#include "game.h"
#include "map.h"
#include "raylib.h"
#include "structs.h"
#include <time.h>

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

    //modify the projectile features
    current_proj.position = (Vector2){SCREENWIDTH/3, SCREENHEIGHT/2};
    current_proj.direction = direction;
    current_proj.filter = WHITE;

    projectiles->array[projectiles->counter] = current_proj;

    projectiles->counter++;
}

void all_plants_shoot(Plant* plants, ProjectileArray* proj_arr) {
    for (int i = 0; i < 1; i++) {
        if (plants[i].rate != no_fire && external_timer(plants[i].rate, &plants[i].time_accum) == 1) {
            plant_shoot(plants[i], proj_arr);
        }
    }
}

void update_projectiles(ProjectileArray* projectiles) {
    for (int i = 0; i < MAXPROJECTILES; i++) {
        projectiles->array[i].position.x += PROJECTILESPEED;
    }
}

void draw_projectiles(ProjectileArray projectiles, GameTextures textures) {
    Projectile proj;
    static float rotation = 0.0;

    if (rotation >= 360) //degrees
        rotation = 0.0;

    for (int i = 0; i < MAXPROJECTILES; i++) {
        proj = projectiles.array[i];

        DrawTextureEx(textures.pea_projectile, proj.position, rotation, PROJSCALING, proj.filter);
        //DrawTexture(textures.pea_projectile, proj.position.x, proj.position.y, proj.filter);
    }

    rotation += PROJROTATION;

}

void plants_array_mapping(Plant *plants) {

    plants[0] = (Plant) {
        "Peashooter",
        10,
        50,
        medium,
        0,
        no_fire,
    };

    plants[1] = (Plant) {
        "Sunflower",
        10,
        50,
        slow,
        0,
        no_fire,
    };

}

void plants_textures_mapping(PlantManager *plant_manager) {

    plant_manager->plants[0].texture = LoadTexture("../resources/textures/peashooter.png");

    plant_manager->plants[1].texture = LoadTexture("../resources/textures/sunflower.png");

}

void plant_manager_mapping(PlantManager *plant_manager) {

    plants_array_mapping(plant_manager->plants);

    plants_textures_mapping(plant_manager);

}
