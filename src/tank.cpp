#include "tank.h"
#include <cmath>
#include <iostream>

//if tank is dead waits 2 seconds from last time it was hit then sets it back to alive
void Tank::Update(){
  if(alive == false){
    if(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-death_time).count()>2000) alive = true;
  }
}

//Update tank position (blocks if on edge of map)
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

//Creates a new bullet object and a unique pointer for it then store in projectile vector
void Tank::Fire(int team) {
    projectiles.push_back(std::move(std::make_unique<Bullet>(pos_x,pos_y,direction,team,grid_width,grid_height)));
    std::cout << "FIRE!" << std::endl;
}

//return score
int Tank::GetScore(){
  return score;
}