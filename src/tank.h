#ifndef TANK_H
#define TANK_H

#include <vector>
#include "SDL.h"

class Tank {
public:
    enum class Direction{ kUp, kDown, kLeft, kRight };
    enum class Control{ angleUp, angleDown, powerUp, powerDown };

void Update();
void fire();

float pos_x;
float pos_y;
bool alive{true};
float speed{0.1f};
Direction dir;

private:
void updatePos();
int id;

};

#endif