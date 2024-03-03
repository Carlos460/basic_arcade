#include "SDL2/SDL.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_video.h"
#include "constants.h"
#include "renderer.h"

struct window_manager {
  SDL_Window *window;
} window_manager = {NULL};

int initialize_window(struct window_manager *wm, struct render_manager *rm) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    fprintf(stderr, "Error initializing SDL.\n");
    return FALSE;
  }

  wm->window =
      SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_BORDERLESS);

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
