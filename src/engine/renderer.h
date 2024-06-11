#ifndef RENDERER
#define RENDERER

#include <SDL_render.h>
#include "player.h"
#include "projectile.h"

typedef struct {
  SDL_Renderer *renderer;
} render_manager;

void render(SDL_Renderer *renderer, struct player *player1,
            struct player *player2, struct projectile *ball, struct player *cursor);
#endif // !RENDERER
