#include "tank.h"
#include <cmath>
#include <iostream>

void Tank::Update(){}

void Tank::PosUpdate(Direction input) {
    direction = input;
    switch (input){
        case Direction::kUp:
        pos_y -= speed;
        break;
        case Direction::kDown:
        pos_y += speed;
        break;
        case Direction::kLeft:
        pos_x -= speed;
        break;
        case Direction::kRight:
        pos_x += speed;
        break;
    }
}

void Tank::Fire(int team) {
    Bullet bullet(pos_x,pos_y,direction,team,grid_width,grid_height);
    projectiles.emplace_back(bullet);
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