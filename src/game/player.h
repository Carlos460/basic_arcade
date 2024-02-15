#include "SDL2/SDL_keycode.h"

struct PlayerController {
  SDL_KeyCode up;
  SDL_KeyCode down;
};

struct Player {
  float x;
  float y;
  float width;
  float height;
  int direction;
  struct PlayerController controller;
};
