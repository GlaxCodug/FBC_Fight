#include <stdio.h>
#include "glass.h"

void CreateWindow (Window* window) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_DisplayMode display;
    SDL_GetCurrentDisplayMode(0, &display);

    window->SizeX = display.w * 0.5;
    window->SizeY = display.h * 0.5;

    SDL_CreateWindow(
        "FBC Fight",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        window->SizeX,
        window->SizeY,
        0
    );
}