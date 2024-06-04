#include "window.h"
#include "constants.h"
#include "renderer.h"
#include <stdio.h>
#include <SDL.h>
#include <SDL_render.h>
#include <SDL_video.h>

int initialize_window(window_manager *wm, render_manager *rm) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    fprintf(stderr, "Error initializing SDL.\n");
    return FALSE;
  }

  wm->window =
      SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);

  if (!wm->window) {
    fprintf(stderr, "Error creating SDL Window.\n");
    return FALSE;
  }

  rm->renderer = SDL_CreateRenderer(wm->window, -1, 0);

  if (!rm->renderer) {
    fprintf(stderr, "Error creating SDL Renderer.\n");
    return FALSE;
  }

  return TRUE;
}

void destroy_window(SDL_Window *window, SDL_Renderer *renderer) {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
