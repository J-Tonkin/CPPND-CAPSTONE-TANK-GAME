#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "tank.h"

void Controller::PosUpdate(Tank &tank, Direction input) const {
  tank.PosUpdate(input);
  return;
}

void Controller::Fire(Tank &tank, int team) const {
  tank.Fire(team);
  return;
}

//TODO: Update input to include WASD, E and / input
void Controller::HandleInput(bool &running, Tank &tank1, Tank &tank2) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        //Inputs for direction keys
        case SDLK_UP:
          Controller::PosUpdate(tank1, Direction::kUp);
          break;
        case SDLK_w:
          Controller::PosUpdate(tank2, Direction::kUp);
          break;
        case SDLK_DOWN:
          Controller::PosUpdate(tank1, Direction::kDown);
          break;
        case SDLK_s:
          Controller::PosUpdate(tank2, Direction::kDown);
          break;
        case SDLK_LEFT:
          Controller::PosUpdate(tank1, Direction::kLeft);
          break;
        case SDLK_a:
          Controller::PosUpdate(tank2, Direction::kLeft);
          break;
        case SDLK_RIGHT:
          Controller::PosUpdate(tank1, Direction::kRight);
          break;
        case SDLK_d:
          Controller::PosUpdate(tank2, Direction::kRight);
          break;
        //Input for firing buttons  
        case SDLK_RCTRL:
          Controller::Fire(tank1, 1);
          break;
        case SDLK_SPACE:
          Controller::Fire(tank2, 2);
          break;
      }
    }
  }
}