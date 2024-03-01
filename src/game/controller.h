#ifndef CONTROLLER_H
#define CONTROLLER_H

struct player;

#include "SDL2/SDL_events.h"
#include "SDL2/SDL_keycode.h"

struct controller {
  SDL_KeyCode up;
  SDL_KeyCode down;
};


void controller_handle_events(SDL_Event event, struct player *player);

#endif // !CONTROLLER

