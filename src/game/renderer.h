#ifndef RENDERER
#define RENDERER

#include "SDL2/SDL_render.h"
#include "player.h"
#include "projectile.h"

struct render_manager {
  SDL_Renderer *renderer;
} render_manager = {NULL};

void render(SDL_Renderer *renderer, struct player *player1,
            struct player *player2, struct projectile *ball);
#endif // !RENDERER
