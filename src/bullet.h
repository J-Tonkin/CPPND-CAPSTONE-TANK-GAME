#ifndef BULLET_H
#define BULLET_H

#include <iostream>
#include "controller.h"

class Bullet {
    public:
    Bullet(float pos_x, float pos_y, Direction dir, int team, int grid_width, int grid_height)
       :pos_x(pos_x), 
        pos_y(pos_y),
        dir(dir),
        team(team), 
        grid_width(grid_width), 
        grid_height(grid_height) {};
    void Update();
    float pos_x;
    float pos_y;

    private:
    float speed{0.5f};
    int team;
    int grid_width;
    int grid_height;
    Direction dir{Direction::kUp};
};

#endif