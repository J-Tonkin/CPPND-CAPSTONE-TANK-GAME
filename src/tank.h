#ifndef TANK_H
#define TANK_H

#include <vector>
#include "SDL.h"

class Tank {
public:
    enum class Direction { kUp, kDown, kLeft, kRight };
    enum class Control{ angleUp, angleDown, powerUp, powerDown };

  Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height) {}

void Update();
void fire();

float pos_x;
float pos_y;
bool alive{true};
float speed{0.1f};

private:
void updatePos();

}

#endif