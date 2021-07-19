#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "tank.h"

class Controller {
 public:
  void HandleInput(bool &running, Snake &snake, Snake &snake2) const;

 private:
  void ChangeDirection(Snake &tank, Snake::Direction input) const;
};

#endif