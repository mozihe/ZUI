#include "Button.h"

ZUI::Button::Button(SDL_Rect Rect, SDL_Color Color, SDL_Renderer *Renderer)
{
    rect = Rect;
    color = Color;
    hoverColor = {static_cast<Uint8>(Color.r + 50), static_cast<Uint8>(Color.g + 50), static_cast<Uint8>(Color.b + 50), Color.a};
    pressColor = {static_cast<Uint8>(Color.r - 50), static_cast<Uint8>(Color.g - 50), static_cast<Uint8>(Color.b - 50), Color.a};
    renderer = Renderer;
    texture = nullptr;
}

ZUI::Button::Button(SDL_Rect Rect, SDL_Color Color, SDL_Color HoverColor, SDL_Color PressColor, SDL_Renderer *Renderer)
{
    rect = Rect;
    color = Color;
    hoverColor = HoverColor;
    pressColor = PressColor;
    renderer = Renderer;
    texture = nullptr;
}

ZUI::Button::Button(SDL_Point Location, int Width, int Height, SDL_Color Color, SDL_Renderer *Renderer)
{
    rect = {Location.x, Location.y, Width, Height};
    color = Color;
    hoverColor = {static_cast<Uint8>(Color.r + 50), static_cast<Uint8>(Color.g + 50), static_cast<Uint8>(Color.b + 50), Color.a};
    pressColor = {static_cast<Uint8>(Color.r - 50), static_cast<Uint8>(Color.g - 50), static_cast<Uint8>(Color.b - 50), Color.a};
    renderer = Renderer;
    texture = nullptr;
}

ZUI::Button::Button(SDL_Point Location, int Width, int Height, SDL_Color Color, SDL_Color HoverColor, SDL_Color PressColor, SDL_Renderer *Renderer)
{
    rect = {Location.x, Location.y, Width, Height};
    color = Color;
    hoverColor = HoverColor;
    pressColor = PressColor;
    renderer = Renderer;
    texture = nullptr;
}

ZUI::Button::Button(SDL_Rect Rect, SDL_Renderer *Renderer, SDL_Texture *Texture)
{
    rect = Rect;
    renderer = Renderer;
    texture = Texture;
}

ZUI::Button::Button(SDL_Point Location, int Width, int Height, SDL_Renderer *Renderer, SDL_Texture *Texture)
{
    rect = {Location.x, Location.y, Width, Height};
    renderer = Renderer;
    texture = Texture;
}


bool ZUI::Button::IsPressed(SDL_Event *Event)
{
    if (Event->type == SDL_MOUSEBUTTONDOWN)
    {
        if (Event->button.button == SDL_BUTTON_LEFT)
        {
            int x, y;
            SDL_GetMouseState(&x, &y);
            if (x > rect.x && x < rect.x + rect.w && y > rect.y && y < rect.y + rect.h)
            {
                return true;
            }
        }
    }
    return false;
}

void ZUI::Button::Draw()
{
    int x, y;
    Uint32 mouseState = SDL_GetMouseState(&x, &y); // 一次调用获取位置和状态
    bool isMouseOver = x > rect.x && x < rect.x + rect.w && y > rect.y && y < rect.y + rect.h;

    if (texture != nullptr)
    {
        SDL_RenderCopy(renderer, texture, NULL, &rect);
    }
    else
    {
        if (isMouseOver)
        {
            if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT))
            {
                SDL_SetRenderDrawColor(renderer, pressColor.r, pressColor.g, pressColor.b, pressColor.a);
            }
            else
            {
                SDL_SetRenderDrawColor(renderer, hoverColor.r, hoverColor.g, hoverColor.b, hoverColor.a);
            }
        }
        else
        {
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        }

        SDL_RenderFillRect(renderer, &rect);
    }
}

ZUI::Button *ZUI::CreateButton(SDL_Rect Rect, SDL_Color Color, SDL_Renderer *Renderer)
{
    return new Button(Rect, Color, Renderer);
}

ZUI::Button *ZUI::CreateButton(SDL_Rect Rect, SDL_Color Color, SDL_Color HoverColor, SDL_Color PressColor, SDL_Renderer *Renderer)
{
    return new Button(Rect, Color, HoverColor, PressColor, Renderer);
}

ZUI::Button *ZUI::CreateButton(SDL_Point Location, int Width, int Height, SDL_Color Color, SDL_Renderer *Renderer)
{
    return new Button(Location, Width, Height, Color, Renderer);
}

ZUI::Button *ZUI::CreateButton(SDL_Point Location, int Width, int Height, SDL_Color Color, SDL_Color HoverColor, SDL_Color PressColor, SDL_Renderer *Renderer)
{
    return new Button(Location, Width, Height, Color, HoverColor, PressColor, Renderer);
}

ZUI::Button *ZUI::CreateButton(SDL_Rect Rect, SDL_Renderer *Renderer, SDL_Texture *Texture)
{
    return new Button(Rect, Renderer, Texture);
}


ZUI::Button *ZUI::CreateButton(SDL_Point Location, int Width, int Height, SDL_Renderer *Renderer, SDL_Texture *Texture)
{
    return new Button(Location, Width, Height, Renderer, Texture);
}
