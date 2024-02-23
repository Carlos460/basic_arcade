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
                            float height) {
  p->x = x;
  p->y = y;
  p->width = width;
  p->height = height;
  p->direction_x = 1;
  p->direction_y = 1;
}

void projectile_player_collision(struct projectile *p, struct player *p1, struct player *p2) {
  int projectile_left_side = p->x;
  int projectile_right_side = p->x + p->width;

  if (projectile_left_side <= p1->x + p1->width && p->y >= p1->y && p->y <= p1->y + p1->height) {
    p->direction_x *= -1;
  } 
  if (projectile_right_side >= p2->x && p->y >= p2->y && p->y <= p2->y + p2->height) {
    p->direction_x *= -1;
  } 
}

void projectile_window_collision(struct projectile *p, int window_width, int window_height) {
  // top window collision
  if (p->y <= 0) {
    p->y = 0;
    p->direction_y *= -1;
  }
  
  // bottom window collision
  if (p->y >= window_height - p->height) {
    p->y = window_height - p->height;
    p->direction_y *= -1;
  }
 
  // left and right side of window will score for player
  if (p->x <= 0) {
    p->x = 0;
    p->direction_x *= -1;
  }
 
  if (p->x >= window_width - p->width) {
    p->x = window_width - p->width;
    p->direction_x *= -1;
  }
}

#endif // !PROJECTILE
