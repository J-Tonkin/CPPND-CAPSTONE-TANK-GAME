#include <iostream>
#include <vector>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{64};
  constexpr std::size_t kGridHeight{64};

  std::vector<std::vector<bool>> map;

  map.resize(static_cast<int>(kGridWidth));

  for(int i = 0; i < static_cast<int>(kGridWidth); ++i){
    map[i].resize(static_cast<int>(kGridHeight));
    for(int j = 0; j < static_cast<int>(kGridHeight); ++j){
      map[i][j] = false;
    }
  }

  for(int i = ((kGridWidth/2) - 5); i < ((kGridWidth/2) + 5); ++i){
    for(int j = 0; j < kGridHeight; ++j){
      map[i][j] = true;
    }
  }

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight, map);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  //std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}