#ifndef WINDOW_H
#define WINDOW_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_video.h"
#include "constants.h"
#include "renderer.h"

typedef struct {
  SDL_Window *window;
} window_manager;

int initialize_window(window_manager *wm, render_manager *rm);

void destroy_window(SDL_Window *window, SDL_Renderer *renderer);

#endif // !WINDOW_H
