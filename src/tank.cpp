#include "tank.h"
#include <cmath>
#include <iostream>

void Tank::Update(){}

void Tank::PosUpdate(Direction input) {
    direction = input;
    switch (input){
        case Direction::kUp:
          if(pos_y > 0) pos_y -= speed;
          break;
        case Direction::kDown:
          if(pos_y < grid_height-1) pos_y += speed;
          break;
        case Direction::kLeft:
          if(pos_x > 0) pos_x -= speed;
          break;
        case Direction::kRight:
          if(pos_x < grid_width-1) pos_x += speed;
          break;
    }
}

void Tank::Fire(int team) {
    projectiles.push_back(std::move(std::make_unique<Bullet>(pos_x,pos_y,direction,team,grid_width,grid_height)));
    std::cout << "Number of bullets: " << projectiles.size() << std::endl;
    std::cout << "FIRE!" << std::endl;
}

//Checking if a cell is occupied with a tank
bool Tank::TankCell(int x, int y, Tank &tank) {
  if (x == static_cast<int>(tank.pos_x) && y == static_cast<int>(tank.pos_y)) {
    return true;
  }
  return false;
}