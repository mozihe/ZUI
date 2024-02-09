#include "Text.h"

ZUI::Text::Text(SDL_Point Location, SDL_Color Color, SDL_Renderer *Renderer, TTF_Font *font, std::string text, bool IfMid)
{
    renderer = Renderer;
    color = Color;
    rect.x = Location.x;
    rect.y = Location.y;
    ifMid = IfMid;
    SDL_Surface *surface = TTF_RenderUTF8_Blended(font, text.c_str(), color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    if (ifMid)
    {
        rect.x -= rect.w / 2;
        rect.y -= rect.h / 2;
    }
    SDL_FreeSurface(surface);
}

void ZUI::Text::Draw()
{
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

ZUI::Text *ZUI::CreateText(SDL_Point Location, SDL_Color Color, SDL_Renderer *Renderer, TTF_Font *font, std::string text, bool IfMid)
{
    return new Text(Location, Color, Renderer, font, text, IfMid);
}