#include "plants.h"
#include "buttons.h"
#include "clock.h"
#include "game.h"
#include "map.h"
#include "raylib.h"
#include "structs.h"
#include <stdio.h>
#include <string.h>

char plant_code(Plant plant) { return plant.name[0]; }

int parse_plant(char code, Plant *array, Plant *plant) {
    for (int i = 0; i < HOWMANYPLANTS; i++) {
        if (array[i].name[0] == code) {
            *plant = array[i];
            return 1;
        }
    }
    return -1;
}

void plant_shoot(Plant plant, int x, int y, ProjectileArray *projectiles) {

    int direction;

    Vector2 starting_position = {BIGBLANKSPACE,
                                 THEGAMEBELOWTHAT + BIGBLANKSPACE};

    Vector2 tile_size = {3 * PLANTSPRITESIZE, 3 * PLANTSPRITESIZE};

    Projectile current_proj;

    current_proj.position = starting_position;
    current_proj.position.x += tile_size.x * (x + 1);
    current_proj.position.y += tile_size.y * y + tile_size.y / 3;

    if (projectiles->counter >= MAXPROJECTILES)
        projectiles->counter = 0;

    if (plant.effects == gen_sun) {
        direction = 0;
        current_proj.effect = gen_sun;

        sprintf(current_proj.text, "%c", roll_a_dice(26) + 64);

    } else {
        direction = 1;
    }

    // modify the projectile features
    current_proj.direction = direction;
    current_proj.filter = WHITE;

    projectiles->array[projectiles->counter] = current_proj;

    projectiles->counter++;
}

void all_plants_shoot(Plant *plants, ProjectileArray *proj_arr,
                      SmartMap *smart_map) {
    Plant plant_to_shoot = {0};

    for (int i = 0; i < MAXMAPROWS; i++) {
        for (int j = 0; j < MAXMAPCOLLUMS; j++) {
            if (parse_plant(smart_map->map[i][j], plants, &plant_to_shoot) ==
                1) {
                if (plant_to_shoot.rate != no_fire &&
                    external_timer(plant_to_shoot.rate,
                                   &smart_map->timer[i][j]) == 1) {
                    plant_shoot(plant_to_shoot, j, i, proj_arr);
                }
            }
        }
    }
}

void update_projectiles(ProjectileArray *projectiles, int *sun_stack) {
    for (int i = 0; i < MAXPROJECTILES; i++) {
        projectiles->array[i].position.x +=
            projectiles->array[i].direction * PROJECTILESPEED;

        char comp = projectiles->array[i].text[0];

        if (IsKeyPressed(comp)) {
            projectiles->array[i].position.x = -SCREENWIDTH;
            projectiles->array[i].text[0] = '\0';
            (*sun_stack) += 25;
        }
    }
}

void draw_projectiles(ProjectileArray projectiles, GameTextures textures) {
    Projectile proj;
    static float rotation = 0.0;

    if (rotation >= 360) // degrees
        rotation = 0.0;

    for (int i = 0; i < MAXPROJECTILES; i++) {
        proj = projectiles.array[i];

        if (proj.effect == no) {
            DrawTextureEx(textures.pea_projectile, proj.position, rotation,
                          PROJSCALING, proj.filter);
        } else if (proj.effect == gen_sun) {
            Button sun_button = {
                proj.position,
                (Vector2){SCREENWIDTH / 20, SCREENWIDTH / 20},
                textures.sun,
            };

            strcpy(sun_button.text, proj.text);
            sun_button.text_color = DARKGRAY;
            sun_button.selected = false;

            button_draw_texture(sun_button, PROJSCALING / 2);
        }
    }

    rotation += PROJROTATION;
}

void plants_array_mapping(Plant *plants) {

    plants[0] = (Plant){
        "Peashooter", 10, 100, medium, no,
    };
    plants[0].timer_accum = plants[0].rate;

    plants[1] = (Plant){
        "Sunflower", 10, 50, slow, gen_sun,
    };
    plants[1].timer_accum = plants[1].rate;
}

void plants_textures_mapping(PlantManager *plant_manager) {

    plant_manager->plants[0].texture =
        LoadTexture("../resources/textures/peashooter.png");

    plant_manager->plants[1].texture =
        LoadTexture("../resources/textures/sunflower.png");
}

void plant_manager_mapping(PlantManager *plant_manager) {

    plants_array_mapping(plant_manager->plants);

    plants_textures_mapping(plant_manager);
}

void update_plant_timer(PlantManager *plant_manager) {
    for (int i = 0; i < HOWMANYPLANTS; i++) {
        plant_manager->plants[i].timer_accum += GetFrameTime();
    }
}
