#include "./constants.h"
#include "./game/player.h"
#include "./game/controller.h"
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

int initialize_window(void) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    fprintf(stderr, "Error initializing SDL.\n");
    return FALSE;
  }

  window =
      SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_BORDERLESS);

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
  // player 1 setup
  player_constructor(&player1, 50, 100, 15, 100);

  struct controller controller1 = {SDLK_a, SDLK_d};
  player1.controller = controller1;

  // player 2 setup
  player_constructor(&player2, 750, 100, 15, 100);

  struct controller controller2 = {SDLK_LEFT, SDLK_RIGHT};
  player2.controller = controller2;
}

void handle_controller_events(SDL_Event event, struct player *player) {
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

void process_input(void) {
  SDL_Event event;
  SDL_PollEvent(&event);

  // quit game
  if (event.type == SDL_QUIT)
    game_is_running = FALSE;
  if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
    game_is_running = FALSE;

  // player input
  handle_controller_events(event, &player1);
  handle_controller_events(event, &player2);
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

  player1.y += SPEED * delta_time * player1.direction;
  player2.y += SPEED * delta_time * player2.direction;

  player_window_collision(&player1, WINDOW_WIDTH, WINDOW_HEIGHT);
  player_window_collision(&player2, WINDOW_WIDTH, WINDOW_HEIGHT);
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

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
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

  while (game_is_running) {
    process_input();
    update();
    render();
  }

  destroy_window();

  return 0;
}
