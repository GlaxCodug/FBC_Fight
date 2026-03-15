#ifndef GLASS_H
#define GLASS_H

#include <SDL2/SDL.h>

typedef struct {
    SDL_Window* sdl_window;
    int SizeX;
    int SizeY;
} Window;

void CreateWindow(Window* window);

#endif