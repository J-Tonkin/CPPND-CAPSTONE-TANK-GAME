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

  std::vector<std::vector<bool>> map;                         //Map showing if terrain is present or not

  map.resize(static_cast<int>(kGridWidth));                   //resize vector to ensure we don't access a position that doesn't exist
  for(int i = 0; i < static_cast<int>(kGridWidth); ++i){      //iterate through each vector
    map[i].resize(static_cast<int>(kGridHeight));             //resize internal vectors
    for(int j = 0; j < static_cast<int>(kGridHeight); ++j){   //iterate through each element of internal vector
      map[i][j] = false;                                      //set all values to false
    }
  }

  for(int i = ((kGridWidth/2) - 5); i < ((kGridWidth/2) + 5); ++i){ //insert a strip of terrain in the centre
    for(int j = 0; j < kGridHeight; ++j){
      map[i][j] = true;
    }
  }

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight, map);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  if(game.GetTank1Score() > game.GetTank2Score()){
    std::cout << "Tank 1 Wins!" << std::endl;
  } else if (game.GetTank2Score() > game.GetTank1Score()) {
    std::cout << "Tank 2 Wins!" << std::endl;
  } else {
    std::cout << "Its a draw!" << std::endl;
  }
  return 0;
}