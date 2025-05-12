#include "zombies.h"
#include "buttons.h"
#include "clock.h"
#include "game.h"
#include "raylib.h"
#include "structs.h"
#include <stdio.h>
#include <stdbool.h>
                //THIS ARRAY MUST HAVE TOTAL ZOMBIES SIZE!!!1      
void zombie_spawn(int total_zombies, Zombie *zombies) {
    static int zombies_spawned = 0;
    static float last_spawned_was = 0;

    last_spawned_was += GetFrameTime();

    if (zombies_spawned < total_zombies && last_spawned_was > 4) {
        
        Zombie new_zombie = {
            ZOMBIEINITIALHP,
            roll_a_dice(MAXMAPROWS) - 1,
            SCREENWIDTH,
            true,
        };

        printf("spawnou um na linha %d\n", new_zombie.row + 1);

        zombies[zombies_spawned] = new_zombie;

        zombies_spawned++;
        last_spawned_was = 0;
    }
}

void zombies_walk(int total_zombies, Zombie *zombies) {
    for (int i = 0; i < total_zombies; i++) {
        if(zombies[i].alive)
            zombies[i].coord_x -= ZOMBIESPEED;
    }
}

void zombies_bite(SmartMap *smart_map, Zombie *zombies, int total_zombies) {

    Vector2 starting_position = {
        BIGBLANKSPACE,
        THEGAMEBELOWTHAT
    };

    Vector2 tile_size = {3*PLANTSPRITESIZE, 4*PLANTSPRITESIZE};

    for (int i = 0; i < total_zombies; i++) {
        if (zombies[i].alive && 
            zombies[i].coord_x < starting_position.x + MAXMAPCOLLUMS * 3 * PLANTSPRITESIZE
        && zombies[i].coord_x > SMALLBLANKSPACE) {
            smart_map->map[zombies[i].row][(int)(zombies[i].coord_x 
                - starting_position.x)/3
            ] = 'G';
        }
    }
}

void zombies_damage_take(ProjectileArray *projectiles, Zombie *zombies, int total_zombies) {
    for (int i = 0; i < total_zombies; i++) {

        Button zombie_button = {
            (Vector2) {zombies[i].coord_x, THEGAMEBELOWTHAT + 4*PLANTSPRITESIZE*zombies[i].row},
            (Vector2) {3*PLANTSPRITESIZE, 4*PLANTSPRITESIZE},
        };

        Rectangle zombie_rect = get_button_rect(zombie_button);

        for (int j = 0; j < MAXPROJECTILES; j++) {
            if (CheckCollisionPointRec(projectiles->array[j].position, zombie_rect)) {
                projectiles->array[j].position.x = 10*SCREENWIDTH;
                zombies[i].life_points -= 20;

                printf("Acertou \n");

                if (zombies[i].life_points <= 0) {
                    zombies[i].alive = false;
                    zombies[i].coord_x = -10*SCREENWIDTH;
                }
            }
        }

    }
}

void zombies_draw(GameTextures textures, Zombie *zombies, int total_zombies) {

    for (int i = 0; i < total_zombies; i++) {
        Button zombie_button = {
            (Vector2) {zombies[i].coord_x, THEGAMEBELOWTHAT + 4*PLANTSPRITESIZE*zombies[i].row},
            (Vector2) {3*PLANTSPRITESIZE, 4*PLANTSPRITESIZE},
            textures.logo,
            "",
            BLACK,
            false,
        };

        button_draw_texture(zombie_button, 1);
    }
}
