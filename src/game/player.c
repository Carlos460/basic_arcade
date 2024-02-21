#include "player.h"

void player_constructor(struct player *p, float x, float y, float width,
                   float height) {
  p->x = x;
  p->y = y;
  p->width = width;
  p->height = height;
}

void player_window_collision(struct player *p, int window_width,
                             int window_height) {
  if (p->y <= 0) {
    p->y = 0;
  } else if (p->y >= window_height - p->height) {
    p->y = window_height - p->height;
  }
}

void player_attach_controller(struct player *p, struct controller c) {
  p->controller = c;
}
