#include <stdio.h>
#include <SDL2/SDL.h>
#include "glass.h"

int loop = 1;

int main(int argc, char* argv[]) {
    Window window;

    CreateWindow(&window);

    while (loop == 1) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                loop = 0;
                SDL_DestroyWindow(window.sdl_window);
                SDL_Quit();
            }
        }
    }
    return 0;
}