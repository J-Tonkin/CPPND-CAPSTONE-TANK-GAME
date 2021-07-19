#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"
#include "tank.h"

void Controller::ChangeDirection(Snake &tank, Snake::Direction input) const {
  //Key input function
  tank.direction = input;
  return;

}

//TODO: Update input to include WASD, E and / input
void Controller::HandleInput(bool &running, Snake &snake, Snake &snake2) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          //Insert function call to whatever button does
          Controller::ChangeDirection(snake, Snake::Direction::kUp);
          break;

        case SDLK_DOWN:
        Controller::ChangeDirection(snake, Snake::Direction::kDown);
          //
          break;

        case SDLK_LEFT:
        Controller::ChangeDirection(snake, Snake::Direction::kLeft);
          //
          break;

        case SDLK_RIGHT:
        Controller::ChangeDirection(snake, Snake::Direction::kRight);
          //
          break;

        case SDLK_RCTRL:
        Controller::ChangeDirection(snake, Snake::Direction::kUp);
          //Key input
          break;

        case SDLK_w:
          Controller::ChangeDirection(snake2, Snake::Direction::kUp);
          break;

        case SDLK_s:
          Controller::ChangeDirection(snake2, Snake::Direction::kDown);
          break;

        case SDLK_a:
          Controller::ChangeDirection(snake2, Snake::Direction::kLeft);
          break;

        case SDLK_d:
          Controller::ChangeDirection(snake2, Snake::Direction::kRight);
          break;

        case SDLK_SPACE:
          //Key input
          break;
      }
    }
  }
}