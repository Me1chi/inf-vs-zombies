#include "raylib.h"
#include <stdio.h>
#include "game.h"

int main(void) {

    InitWindow(SCREENWIDTH, SCREENHEIGHT, "INF vs Zombies");

    SetTargetFPS(60);

    char map[3][4] = {
        {'G', 'G', 'G', 'G'},
        {'G', 'G', 'G', 'G'},
        {'G', 'G', 'G', 'G'},
    };

    Vector2 peashooter_pos = {
        1,
        3,
    };

    Plant peashooter = {
        "Peashooter",
        peashooter_pos,
        10,
        slow,
        no,
    };

    insert_plant(peashooter, map);

    for (int i = 0; i < MAXMAPROWS; i++) {
        for (int j = 0; j < MAXMAPCOLLUMS; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }

    while(!WindowShouldClose()) {
        // Game update space





        // Drawing space
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("All working by now", SCREENWIDTH/2, SCREENHEIGHT/2, 20, BLUE);

        EndDrawing();

    }

    CloseWindow();

    printf("Hello, World!\n");

    return 0;
}
