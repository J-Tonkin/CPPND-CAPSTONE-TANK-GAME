#ifndef CONTROLLER_H
#define CONTROLLER_H

enum class Direction { kUp, kDown, kLeft, kRight, none };
class Tank;

class Controller {
 public:
  void HandleInput(bool &running, Tank &tank1, Tank &tank2) const;
  Direction dir = Direction::none;

 private:
  void PosUpdate(Tank &tank, Direction input) const;
  void Fire(Tank &tank, int team) const;
};

#endif