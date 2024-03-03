#include "./game/constants.h"
#include "./game/controller.h"
#include "./game/player.h"
#include "./game/projectile.h"
#include "./game/renderer.h"
#include "./game/window.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_keycode.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_timer.h"

int game_is_running = FALSE;

int last_frame_time = 0;

void setup(void) {
  // player 1 setup
  player_constructor(&player1, 50, 100, 10, 100);

  struct controller controller1 = {SDLK_a, SDLK_d};
  player_attach_controller(&player1, controller1);

  // player 2 setup
  player_constructor(&player2, 750, 100, 10, 100);

  struct controller controller2 = {SDLK_LEFT, SDLK_RIGHT};
  player_attach_controller(&player2, controller2);

  // ball setup
  projectile_constructor(&ball, 100, 100, 15, 15);
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
  controller_handle_events(event, &player1);
  controller_handle_events(event, &player2);
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

  ball.x += SPEED * delta_time * ball.direction_x;
  ball.y += SPEED * delta_time * ball.direction_y;

  projectile_window_collision(&ball, WINDOW_WIDTH, WINDOW_HEIGHT);
  projectile_player_collision(&ball, &player1, &player2);
  player_window_collision(&player1, WINDOW_WIDTH, WINDOW_HEIGHT);
  player_window_collision(&player2, WINDOW_WIDTH, WINDOW_HEIGHT);
}

int main() {
  game_is_running = initialize_window(&window_manager, &render_manager);

  setup();

  while (game_is_running) {
    process_input();
    update();
    render(render_manager.renderer, &player1, &player2, &ball);
  }

  destroy_window(window_manager.window, render_manager.renderer);

  return 0;
}
