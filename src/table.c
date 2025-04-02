#include "table.h"
#include "plants.h"
#include "raylib.h"
#include "structs.h"
#include "game.h"
#include "buttons.h"
#include <stdbool.h>
#include <stdio.h>

void draw_game_grid(char map[MAXMAPROWS][MAXMAPCOLLUMS], GameTextures textures, Plant* plants) {

    char plant_code = '\0';
    int div_mod_ij = 0;
    Plant plant_to_draw;

    Vector2 starting_position = {
        BIGBLANKSPACE,
        THEGAMEBELOWTHAT + BIGBLANKSPACE
    };

    Vector2 tile_size = {3*PLANTSPRITESIZE, 3*PLANTSPRITESIZE};
    Vector2 plant_size = tile_size;

    Button tile = {
        starting_position,
        tile_size,
        textures.grass[div_mod_ij],
        "",
        BLACK,
        false,
    };

    Button plant_button = {
        starting_position,
        plant_size,
        textures.grass[div_mod_ij],
        "",
        BLACK,
        false,
    };

    for (int i = 0; i < MAXMAPROWS; i++) {
        for (int j = 0; j < MAXMAPCOLLUMS; j++) {

            div_mod_ij = (i + j)%2;

            tile.position.x = starting_position.x + j*plant_size.x;
            tile.position.y = starting_position.y + i*plant_size.y;

            tile.texture = textures.grass[div_mod_ij];

            button_draw_texture(tile, TEXTTOBUTTONSIZE);

            switch (map[i][j]) {
                case 'G':


                    break;

                case 'T':



                    break;

                default:
                    if (parse_plant(map[i][j], plants, &plant_to_draw) == 1) {
                        plant_button.texture = plant_to_draw.texture;
                    }

                    plant_button.position.x = tile.position.x;
                    plant_button.position.y = tile.position.y;

                    button_draw_texture(plant_button, TEXTTOBUTTONSIZE);

                    plant_button.texture = textures.grass[div_mod_ij];
                    break;
            }


        }
    }

}
