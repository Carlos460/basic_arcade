#ifndef WINDOW_H
#define WINDOW_H

#include "constants.h"
#include "renderer.h"

#include <SDL.h>
#include <SDL_render.h>
#include <SDL_video.h>

typedef struct {
  SDL_Window *window;
} window_manager;

int initialize_window(window_manager *wm, render_manager *rm);

void destroy_window(SDL_Window *window, SDL_Renderer *renderer);

#endif // !WINDOW_H
