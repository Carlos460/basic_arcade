#ifndef PLAYER_H
#define PLAYER_H

#include "controller.h"
struct controller;

struct player {
  float x;
  float y;
  float width;
  float height;
  int direction;
  struct controller controller;
};

void player_constructor(struct player *p, float x, float y, float width,
                        float height);

void player_window_collision(struct player *p, int window_width,
                             int window_height);

void player_attach_controller(struct player *p, struct controller c);
  
#endif /* ifndef PLAYER */
