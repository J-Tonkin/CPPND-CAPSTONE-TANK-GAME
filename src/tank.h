#ifndef TANK_H
#define TANK_H

#include <vector>
#include <memory>
#include <chrono>
#include "SDL.h"
#include "bullet.h"
#include "controller.h"

class Tank {
 public:
  
  Tank(int grid_width, int grid_height, int start)
      : grid_width(grid_width),
        grid_height(grid_height),
        pos_x((grid_width / 3) * start),
        pos_y((grid_height / 3) * start) {}

  void Update();
  void Fire(int team);
  void PosUpdate(Direction input);
  int GetScore();

  Direction direction = Direction::kUp;

  float speed{1.0f};
  int size{1};
  bool alive{true};
  float pos_x;
  float pos_y;
  int score{0};
  std::chrono::steady_clock::time_point death_time;
  std::vector<std::unique_ptr<Bullet>> projectiles;
 
 private:
  int grid_width;
  int grid_height;
  
};

#endif