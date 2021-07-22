#include "game.h"
#include <iostream>
#include <memory>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : tank1(grid_width, grid_height, 1),
      tank2(grid_width, grid_height, 2),
      grid_width(grid_width),
      grid_height(grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  //PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, tank1, tank2);
    Update();
    renderer.Render(tank1, tank2);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}
/*
void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}
*/
void Game::Update() {
  //update bullet positions 
  for(size_t i = 0; i < tank1.projectiles.size(); i++){
    (tank1.projectiles[i])->Update();
    if(tank1.projectiles[i]->pos_x > grid_width || tank1.projectiles[i]->pos_x < 0 || tank1.projectiles[i]->pos_y < 0 || tank1.projectiles[i]->pos_y > grid_height){
      tank1.projectiles.erase(tank1.projectiles.begin()+i);
    }
  }
  for(size_t i = 0; i < tank2.projectiles.size(); i++){
    (tank2.projectiles[i])->Update();
    if(tank2.projectiles[i]->pos_x > grid_width || tank2.projectiles[i]->pos_x < 0 || tank2.projectiles[i]->pos_y < 0 || tank2.projectiles[i]->pos_y > grid_height){
      tank2.projectiles.erase(tank2.projectiles.begin()+i);
    }
  }
  
  //Check if tanks are still alive
  if (!tank1.alive || !tank2.alive) return; 
  
  //Check if a bullet has hit a tank
  
  
}

int Game::GetScore() const { return score; }