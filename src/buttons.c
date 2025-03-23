#include "buttons.h"
#include "raylib.h"
#include "game.h"

void draw_centralized_text(Button button) {

    float font_size = button.size.y/BUTTONLENGTHOVERFONT;

    Vector2 text_size = MeasureTextEx(GetFontDefault(), button.text, font_size, 3);

    button.position.x += button.size.x/2.0 - text_size.x/2.0;
    button.position.y += button.size.y/2.0 - text_size.y/2.0;

    DrawTextEx(GetFontDefault(), button.text, button.position, font_size, 3, button.text_color);

}

int draw_button(Button button, bool clickable) {

    Rectangle button_rec = {
        button.position.x,
        button.position.y,
        button.size.x,
        button.size.y,
    };

    float delta = SCREENWIDTH/BUTTONLINETHICKNESSDIV;

    bool hovering = false;
    int click = 0;
    Vector2 mouse_pointer = GetMousePosition();

    //button highlight and click
    if (CheckCollisionPointRec(mouse_pointer, button_rec) && clickable) {
        hovering = true;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            click = 1;
    }

    DrawRectangleRounded(button_rec, STDBUTTONCURVE, 10, BLACK);

    button_rec.x += delta;
    button_rec.y += delta;
    button_rec.width -= 2*delta;
    button_rec.height -= 2*delta;

    DrawRectangleRounded(button_rec, STDBUTTONCURVE, 10, button.color);

    //button text drawing
    draw_centralized_text(button);

    //button highlight drawing
    if (hovering) {
        DrawRectangleRounded(button_rec, STDBUTTONCURVE, 20, BUTTONSHADOWCOLOR);
    }

}
