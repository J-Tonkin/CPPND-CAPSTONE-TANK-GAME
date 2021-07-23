
#include "bullet.h"

//Progresses bullets position based on its speed and position (speed should be fixed)
void Bullet::Update(){
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
}