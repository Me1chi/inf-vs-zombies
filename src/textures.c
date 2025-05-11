#include <string.h>
#include "textures.h"
#include "raylib.h"
#include "structs.h"

#define TEXTUREPATH "../resources/textures/"

Texture2D load_texture_from_resources(char *texture_name, GameTextures *textures) {

    char full_path[256];
    strcpy(full_path, TEXTUREPATH);
    strcat(full_path, texture_name);

    return LoadTexture(full_path);
}

void load_general_textures(GameTextures *textures) {

    // Initialize the general textures
    textures->logo = load_texture_from_resources("logo.png", textures);
    
    textures->button = load_texture_from_resources("button.png", textures);
    textures->button_text = load_texture_from_resources("button-text.png", textures);

    textures->sun = load_texture_from_resources("sun.png", textures);
    textures->grass[0] = load_texture_from_resources("grass.png", textures);
    textures->grass[1] = load_texture_from_resources("dirt.png", textures);
    textures->pea_projectile = load_texture_from_resources("peashooter-proj.png", textures);

    textures->menu_background = load_texture_from_resources("menu-background.png", textures);
    textures->menu_play_button = load_texture_from_resources("play-button.png", textures);
    textures->menu_leaderboard_button = load_texture_from_resources("leaderboard-button.png", textures);
    textures->menu_exit_button = load_texture_from_resources("exit-button.png", textures);
    textures->leaderboard = load_texture_from_resources("leaderboard.png", textures);

}
