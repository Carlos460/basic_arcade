#ifndef PROJECTILE
#define PROJECTILE

#include "./player.h"

struct projectile {
  float x;
  float y;
  float width;
  float height;
  int direction_x;
  int direction_y;
} ball;

void projectile_constructor(struct projectile *p, float x, float y, float width,
                            float height);

void projectile_player_collision(struct projectile *p, struct player *p1,
                                 struct player *p2);

void projectile_window_collision(struct projectile *p, int window_width,
                                 int window_height);

#endif // !PROJECTILE
