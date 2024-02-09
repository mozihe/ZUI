#ifndef ZUI_BUTTON_H
#define ZUI_BUTTON_H

#include <SDL2/SDL.h>

namespace ZUI {
    class Button
    {
    public:
        Button(){};
        Button(SDL_Point Location, int Width, int Height, SDL_Color Color, SDL_Color HoverColor, SDL_Color PressColor, SDL_Renderer* Renderer);
        Button(SDL_Point Location, int Width, int Height, SDL_Color Color, SDL_Renderer* Renderer);
        Button(SDL_Rect Rect, SDL_Color Color, SDL_Color HoverColor, SDL_Color PressColor, SDL_Renderer* Renderer);
        Button(SDL_Rect Rect, SDL_Color Color, SDL_Renderer* Renderer);
        Button(SDL_Point Location, int Width, int Height, SDL_Renderer* Renderer, SDL_Texture* Texture);
        Button(SDL_Rect Rect, SDL_Renderer* Renderer, SDL_Texture* Texture);
        bool IsPressed(SDL_Event* Event);
        void Draw();
    private:
        SDL_Rect rect;
        SDL_Color color;
        SDL_Color hoverColor;
        SDL_Color pressColor;
        SDL_Renderer* renderer;
        SDL_Texture* texture;
    };

    Button* CreateButton(SDL_Point Location, int Width, int Height, SDL_Color Color, SDL_Color HoverColor, SDL_Color PressColor, SDL_Renderer* Renderer);
    Button* CreateButton(SDL_Point Location, int Width, int Height, SDL_Color Color, SDL_Renderer* Renderer);
    Button* CreateButton(SDL_Rect Rect, SDL_Color Color, SDL_Color HoverColor, SDL_Color PressColor, SDL_Renderer* Renderer);
    Button* CreateButton(SDL_Rect Rect, SDL_Color Color, SDL_Renderer* Renderer);
    Button* CreateButton(SDL_Point Location, int Width, int Height, SDL_Renderer* Renderer, SDL_Texture* Texture);
    Button* CreateButton(SDL_Rect Rect, SDL_Renderer* Renderer, SDL_Texture* Texture);

}

#endif
