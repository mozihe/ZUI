#include <SDL2/SDL.h>
#include "Button.h"
#include <SDL2_gfxPrimitives_font.h>
#include <SDL2/SDL_image.h>
#include "Text.h"

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    TTF_Init();
    SDL_Window* window = SDL_CreateWindow("NewYear", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Surface* imgSurface = IMG_Load("../pic/try.jpg");
    SDL_Texture* imgTexture = SDL_CreateTextureFromSurface(renderer, imgSurface);
    SDL_FreeSurface(imgSurface);
    ZUI::Button *button;
    button = ZUI::CreateButton({100, 100, 100, 100}, renderer, imgTexture);
    ZUI::Button *button2;
    button2 = ZUI::CreateButton({200, 200, 100, 100}, {255, 0, 0, 255}, {0, 255, 0, 255}, {0, 0, 255, 255}, renderer);
    ZUI::Text *text;
    TTF_Font *font = TTF_OpenFont("../font/NotoSerifSC-VF.ttf", 24);
    text = ZUI::CreateText({320, 240}, {0, 0, 0, 255}, renderer, font, u8"你好, World!", true);
    bool running = true;
    int FPS = 60;
    int frameDelay = 1000 / FPS;
    SDL_Event event;
    while (running)
    {
        Uint32 frameStart = SDL_GetTicks();
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;
            if (button->IsPressed(&event))
                running = false;
            if (button2->IsPressed(&event))
                printf("Button2 Pressed\n");
        }
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        button->Draw();
        button2->Draw();
        text->Draw();
        SDL_RenderPresent(renderer);

        Uint32 frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }
    SDL_DestroyTexture(imgTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();

    return 0;
}
