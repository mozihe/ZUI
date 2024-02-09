#ifndef ZUI_LONGPRESSBUTTON_H
#define ZUI_LONGPRESSBUTTON_H

#include "Button.h"

namespace ZUI
{
    class LongPressButton : public Button
    {
    public:
        LongPressButton():Button(){};
        LongPressButton(SDL_Point Location, int Width, int Height, SDL_Color Color, SDL_Color HoverColor, SDL_Color PressColor, SDL_Renderer* Renderer):Button(Location, Width, Height, Color, HoverColor, PressColor, Renderer){};
        LongPressButton(SDL_Point Location, int Width, int Height, SDL_Color Color, SDL_Renderer* Renderer):Button(Location, Width, Height, Color, Renderer){};
        LongPressButton(SDL_Rect Rect, SDL_Color Color, SDL_Color HoverColor, SDL_Color PressColor, SDL_Renderer* Renderer):Button(Rect, Color, HoverColor, PressColor, Renderer){};
        LongPressButton(SDL_Rect Rect, SDL_Color Color, SDL_Renderer* Renderer):Button(Rect, Color, Renderer){};
        LongPressButton(SDL_Point Location, int Width, int Height, SDL_Renderer* Renderer, SDL_Texture* Texture):Button(Location, Width, Height, Renderer, Texture){};
        LongPressButton(SDL_Rect Rect, SDL_Renderer* Renderer, SDL_Texture* Texture):Button(Rect, Renderer, Texture){};
        bool IsPressed(SDL_Event *Event) override;
        bool checkPressed();
    private:
        bool isPressed = false;
    };

    LongPressButton* CreateLongPressButton(SDL_Point Location, int Width, int Height, SDL_Color Color, SDL_Color HoverColor, SDL_Color PressColor, SDL_Renderer* Renderer);
    LongPressButton* CreateLongPressButton(SDL_Point Location, int Width, int Height, SDL_Color Color, SDL_Renderer* Renderer);
    LongPressButton* CreateLongPressButton(SDL_Rect Rect, SDL_Color Color, SDL_Color HoverColor, SDL_Color PressColor, SDL_Renderer* Renderer);
    LongPressButton* CreateLongPressButton(SDL_Rect Rect, SDL_Color Color, SDL_Renderer* Renderer);
    LongPressButton* CreateLongPressButton(SDL_Point Location, int Width, int Height, SDL_Renderer* Renderer, SDL_Texture* Texture);
    LongPressButton* CreateLongPressButton(SDL_Rect Rect, SDL_Renderer* Renderer, SDL_Texture* Texture);
}

#endif
