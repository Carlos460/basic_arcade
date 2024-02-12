#include "./constants.h"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_keycode.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_timer.h"
#include <SDL2/SDL.h>
#include <stdio.h>

int game_is_running = FALSE;
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

int last_frame_time = 0;

struct ball {
  float x;
  float y;
  float width;
  float height;
} player1, player2;

int controller1_direction = 0;
int controller2_direction = 0;

int initialize_window(void) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    fprintf(stderr, "Error initializing SDL.\n");
    return FALSE;
  }

  window = SDL_CreateWindow(
    NULL,
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    SDL_WINDOW_BORDERLESS);
  
  if (!window) {
    fprintf(stderr, "Error creating SDL Window.\n");
    return FALSE;
  }

  renderer = SDL_CreateRenderer(window, -1, 0);
  
  if (!renderer) {
    fprintf(stderr, "Error creating SDL Renderer.\n");
    return FALSE;
  }

  return TRUE;
}

void setup(void) {
  player1.x = 50;
  player1.y = 100;
  player1.width = 15;
  player1.height = 100;
  
  player2.x = 750;
  player2.y = 100;
  player2.width = 15;
  player2.height = 100;
}

void process_input(void) {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
    case SDL_QUIT:
      game_is_running = FALSE;
      break;
    case SDL_KEYDOWN:
      if (event.key.keysym.sym == SDLK_ESCAPE)
        game_is_running = FALSE;
      // player 1
      if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_a)
        controller1_direction = -1;
      if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_d)
        controller1_direction = 1;
      // player 2
      if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_LEFT)
        controller2_direction = -1;
      if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_RIGHT)
        controller2_direction = 1;
      break;
    case SDL_KEYUP:
      // player 1
      if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_a && controller1_direction == -1)
        controller1_direction = 0;
      if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_d && controller1_direction == 1)
        controller1_direction = 0;
      // player 2
      if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_LEFT && controller2_direction == -1)
        controller2_direction = 0;
      if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_RIGHT && controller2_direction == 1)
        controller2_direction = 0;
    default:
      // do nothing
      break;
  }
}

void update(void) {
  // sleep the execution
  int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);

  if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME) {
    SDL_Delay(time_to_wait);
  }
  
  // delta time
  float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;

  last_frame_time = SDL_GetTicks();
  
  player1.y += SPEED * delta_time * controller1_direction;
  player2.y += SPEED * delta_time * controller2_direction;
}

void render(void) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
  SDL_RenderClear(renderer);

  // Draw a rectangle
  SDL_Rect player1_rect = {
    (int)player1.x,
    (int)player1.y,
    (int)player1.width,
    (int)player1.height,
  };
  
  SDL_Rect player2_rect = {
    (int)player2.x,
    (int)player2.y,
    (int)player2.width,
    (int)player2.height,
  };

  SDL_SetRenderDrawColor(renderer, 255, 255,255, 255);
  SDL_RenderFillRect(renderer, &player1_rect);
  SDL_RenderFillRect(renderer, &player2_rect);

  SDL_RenderPresent(renderer);
}

void destroy_window() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

int main() {
  game_is_running = initialize_window();

  setup();
  
  while(game_is_running) {
    process_input();
    update();
    render();
  }

  destroy_window();
  
  return 0;
}
