#include "longPressButton.h"

bool ZUI::LongPressButton::IsPressed(SDL_Event *Event)
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    bool isMouseOver = x > rect.x && x < rect.x + rect.w && y > rect.y && y < rect.y + rect.h;

    if (Event->type == SDL_MOUSEBUTTONDOWN && Event->button.button == SDL_BUTTON_LEFT && isMouseOver)
        isPressed = true;
    else if (Event->type == SDL_MOUSEBUTTONUP && Event->button.button == SDL_BUTTON_LEFT)
        isPressed = false;
    if (isPressed && isMouseOver)
        return true;
    return false;
}

ZUI::LongPressButton *ZUI::CreateLongPressButton(SDL_Point Location, int Width, int Height, SDL_Color Color, SDL_Color HoverColor, SDL_Color PressColor, SDL_Renderer *Renderer)
{
    return new LongPressButton(Location, Width, Height, Color, HoverColor, PressColor, Renderer);
}

ZUI::LongPressButton *ZUI::CreateLongPressButton(SDL_Point Location, int Width, int Height, SDL_Color Color, SDL_Renderer *Renderer)
{
    return new LongPressButton(Location, Width, Height, Color, Renderer);
}

ZUI::LongPressButton *ZUI::CreateLongPressButton(SDL_Rect Rect, SDL_Color Color, SDL_Color HoverColor, SDL_Color PressColor, SDL_Renderer *Renderer)
{
    return new LongPressButton(Rect, Color, HoverColor, PressColor, Renderer);
}

ZUI::LongPressButton *ZUI::CreateLongPressButton(SDL_Rect Rect, SDL_Color Color, SDL_Renderer *Renderer)
{
    return new LongPressButton(Rect, Color, Renderer);
}

ZUI::LongPressButton *ZUI::CreateLongPressButton(SDL_Point Location, int Width, int Height, SDL_Renderer *Renderer, SDL_Texture *Texture)
{
    return new LongPressButton(Location, Width, Height, Renderer, Texture);
}

ZUI::LongPressButton *ZUI::CreateLongPressButton(SDL_Rect Rect, SDL_Renderer *Renderer, SDL_Texture *Texture)
{
    return new LongPressButton(Rect, Renderer, Texture);
}

bool ZUI::LongPressButton::checkPressed()
{
    return isPressed;
}