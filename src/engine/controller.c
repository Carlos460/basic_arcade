#include "SDL2/SDL_events.h"
#include "controller.h"
#include "player.h"

void controller_handle_events(SDL_Event event, struct player *player) {
  struct controller controller = player->controller;
  int direction = player->direction;

  switch (event.type) {
  case SDL_KEYDOWN:
    if (event.key.keysym.sym == controller.up)
      player->direction = -1;
    if (event.key.keysym.sym == controller.down)
      player->direction = 1;
    break;
  case SDL_KEYUP:
    if (event.key.keysym.sym == controller.up && direction == -1)
      player->direction = 0;
    if (event.key.keysym.sym == controller.down && direction == 1)
      player->direction = 0;
    break;
  default:
    // do nothing
    break;
  }
}
