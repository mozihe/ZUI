#ifndef ZUI_TEXT_H
#define ZUI_TEXT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

namespace ZUI {
    class Text
    {
    public:
        Text(){};
        Text(SDL_Point Location, SDL_Color Color, SDL_Renderer* Renderer, TTF_Font* font, std::string text, bool IfMid = false);
        void Draw();
    private:
        SDL_Rect rect;
        bool ifMid;
        SDL_Color color;
        SDL_Renderer* renderer;
        SDL_Texture* texture;
    };
    Text* CreateText(SDL_Point Location, SDL_Color Color, SDL_Renderer* Renderer, TTF_Font* font, std::string text, bool IfMid = false);
}

#endif
