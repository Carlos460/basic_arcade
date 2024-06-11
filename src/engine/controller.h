#pragma once
struct player;

#include <SDL_events.h>
#include <SDL_keycode.h>

struct controller {
  SDL_KeyCode up;
  SDL_KeyCode down;
};


void controller_handle_events(SDL_Event event, struct player *player);
