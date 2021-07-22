#ifndef TANK_H
#define TANK_H

#include <vector>
#include "SDL.h"
#include "bullet.h"
#include "controller.h"

class Tank {
 public:
  
  Tank(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        pos_x(grid_width / 2),
        pos_y(grid_height / 2) {}

  void Update();
  void Fire(int team);
  void PosUpdate(Direction input);
  bool TankCell(int x, int y, Tank &tank);

  Direction direction = Direction::none;

  float speed{1.0f};
  int size{1};
  bool alive{true};
  float pos_x;
  float pos_y;
  std::vector<Bullet> projectiles;
 
 private:
  int grid_width;
  int grid_height;
  
};

#endif