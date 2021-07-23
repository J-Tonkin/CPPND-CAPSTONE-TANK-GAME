#include "game.h"
#include <iostream>
#include <memory>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height, std::vector<std::vector<bool>> &map)
    : tank1(grid_width, grid_height, 1),
      tank2(grid_width, grid_height, 2),
      grid_width(grid_width),
      grid_height(grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)),
      map(map) {}

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
    renderer.Render(tank1, tank2, map);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(tank1.score, tank2.score, frame_count);
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

void Game::Update() {
  tank1.Update();
  tank2.Update();
  for(size_t i = 0; i < tank1.projectiles.size(); i++){
    (tank1.projectiles[i])->Update();
    if((tank1.projectiles[i]->pos_x-tank2.pos_x < 1) && (tank1.projectiles[i]->pos_x-tank2.pos_x > -1) && (tank1.projectiles[i]->pos_y-tank2.pos_y < 1) && (tank1.projectiles[i]->pos_y-tank2.pos_y > -1)){
      tank2.alive = false;
      tank2.death_time = std::chrono::steady_clock::now();
      tank1.score += 1;
      tank1.projectiles.erase(tank1.projectiles.begin()+i);
      return;
    }
    if(CheckEdges(tank1.projectiles[i]->pos_x,tank1.projectiles[i]->pos_y)){
      tank1.projectiles.erase(tank1.projectiles.begin()+i);
      return;
    }
    if(CheckMap(tank1.projectiles[i]->pos_x,tank1.projectiles[i]->pos_y)) {
      SetMap(tank1.projectiles[i]->pos_x, tank1.projectiles[i]->pos_y, false);
      tank1.projectiles.erase(tank1.projectiles.begin()+i);
      return;
    }
    
  }
  for(size_t i = 0; i < tank2.projectiles.size(); i++){
    (tank2.projectiles[i])->Update();
    if((tank2.projectiles[i]->pos_x-tank1.pos_x < 1) && (tank2.projectiles[i]->pos_x-tank1.pos_x > -1) && (tank2.projectiles[i]->pos_y-tank1.pos_y < 1) && (tank2.projectiles[i]->pos_y-tank1.pos_y > -1)){
      tank1.alive = false;
      tank1.death_time = std::chrono::steady_clock::now();
      tank2.score += 1;
      tank2.projectiles.erase(tank2.projectiles.begin()+i);
      return;
    }
    if(CheckEdges(tank2.projectiles[i]->pos_x,tank2.projectiles[i]->pos_y)) {
      tank2.projectiles.erase(tank2.projectiles.begin()+i);
      return;
    }
    if(CheckMap(tank2.projectiles[i]->pos_x,tank2.projectiles[i]->pos_y)) {
      SetMap(tank2.projectiles[i]->pos_x, tank2.projectiles[i]->pos_y, false);
      tank2.projectiles.erase(tank2.projectiles.begin()+i);
      return;
    }
  }

}

//Checks the bool status of a point on the map
bool Game::CheckMap(float x, float y) const {
  if(x >= grid_width) x = grid_width-1; //This was causing a segmentation fault becuase x exceeded the size of the vector
  return map[static_cast<int>(x)][static_cast<int>(y)];
}

//Sets a point on the map (x,y) with bool value
void Game::SetMap(float x, float y, bool value) {
  map[static_cast<int>(x)][static_cast<int>(y)] = value;
}

//Checks is a point (x,y) is outside the grid
bool Game::CheckEdges(float x, float y) const {
  return (x > grid_width || x < 0 || y < 0 || y > grid_height);
}

int Game::GetScore() const { return score; }