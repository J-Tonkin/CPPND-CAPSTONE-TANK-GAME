
#include "bullet.h"

void Bullet::Update(){
    std::cout << "Bullet Direction: "<< dir << std::endl;
    switch (dir){
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
        case Direction::none:
        std::cout << "No direction value" << std::endl;
        break;
        default:
        std::cout << "Default case" << std::endl;
    }
    std::cout << "Bullet x position: " << pos_x << "    Bullet y position: " << pos_y << std::endl;
}