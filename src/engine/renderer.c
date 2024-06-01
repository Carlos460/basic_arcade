#include "player.h"
#include "projectile.h"
#include "SDL2/SDL_render.h"

void render(SDL_Renderer *renderer,struct player *player1, struct player *player2, struct projectile *ball) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
  SDL_RenderClear(renderer);

  // Draw a rectangle
  SDL_Rect player1_rect = {
      (int)player1->x,
      (int)player1->y,
      (int)player1->width,
      (int)player1->height,
  };

  SDL_Rect player2_rect = {
      (int)player2->x,
      (int)player2->y,
      (int)player2->width,
      (int)player2->height,
  };

  SDL_Rect ball_rect = {
    (int)ball->x,
    (int)ball->y,
    (int)ball->width,
    (int)ball->height,
  };

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &player1_rect); 
  SDL_RenderFillRect(renderer, &player2_rect);
  SDL_RenderFillRect(renderer, &ball_rect);

  SDL_RenderPresent(renderer);
}
