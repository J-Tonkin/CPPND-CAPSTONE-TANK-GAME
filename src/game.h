#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "tank.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height, std::vector<std::vector<bool>> &map);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  bool CheckMap(float x, float y) const;
  bool CheckEdges(float x, float y) const;
  void SetMap(float x, float y, bool value);
  int GetTank1Score();
  int GetTank2Score();

 private:
  Tank tank1;
  Tank tank2;

  std::vector<std::vector<bool>> map; //terrain map

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  float grid_width;
  float grid_height;

  void Update();
};

#endif