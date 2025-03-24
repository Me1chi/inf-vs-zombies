#include "buttons.h"
#include "raylib.h"
#include "game.h"

Rectangle get_button_rect(Button button) {
    return (Rectangle) {
        button.position.x,
        button.position.y,
        button.size.x,
        button.size.y,
    };
}

void draw_centralized_text(Button button) {

    float font_size = button.size.y/BUTTONLENGTHOVERFONT;

    Vector2 text_size = MeasureTextEx(GetFontDefault(), button.text, font_size, 3);

    button.position.x += button.size.x/2.0 - text_size.x/2.0;
    button.position.y += button.size.y/2.0 - text_size.y/2.0;

    DrawTextEx(GetFontDefault(), button.text, button.position, font_size, 3, button.text_color);

}

int button_logic(Button button) {
    Rectangle button_rec = get_button_rect(button);

    int click = 0;
    Vector2 mouse_pointer = GetMousePosition();

    if (CheckCollisionPointRec(mouse_pointer, button_rec) && button.clickable && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        click = 1;
    }

    return click;
}

void button_draw(Button button, Color color) {

    Rectangle button_rec = {
        button.position.x,
        button.position.y,
        button.size.x,
        button.size.y,
    };

    float delta = SCREENWIDTH/BUTTONLINETHICKNESSDIV;

    bool hovering = false;
    Vector2 mouse_pointer = GetMousePosition();

    //button highlight and click
    if (CheckCollisionPointRec(mouse_pointer, button_rec) && button.clickable) {
        hovering = true;
    }

    DrawRectangleRounded(button_rec, STDBUTTONCURVE, 10, BLACK);

    button_rec.x += delta;
    button_rec.y += delta;
    button_rec.width -= 2*delta;
    button_rec.height -= 2*delta;

    DrawRectangleRounded(button_rec, STDBUTTONCURVE, 10, color);

    //button text drawing
    draw_centralized_text(button);

    //button highlight drawing
    if (hovering) {
        DrawRectangleRounded(button_rec, STDBUTTONCURVE, 20, BUTTONSHADOWCOLOR);
    }
}

void button_draw_texture(Button button) {

    bool hovering = false;
    Vector2 mouse_pointer = GetMousePosition();

    Rectangle button_rect = get_button_rect(button);
    Rectangle rect_source = {
        0.0f,
        0.0f,
        button.texture.width,
        button.texture.height,
    };

    Vector2 origin = {0,0};

    if (CheckCollisionPointRec(mouse_pointer, button_rect) && button.clickable) {
        hovering = true;
    }

    if (hovering) {
        DrawTexturePro(button.texture, rect_source, button_rect, origin, 0.0f, BUTTONSHADOWCOLOR);
    } else {
        DrawTexturePro(button.texture, rect_source, button_rect, origin, 0.0f, button.filter);
    }

    draw_centralized_text(button);

}
