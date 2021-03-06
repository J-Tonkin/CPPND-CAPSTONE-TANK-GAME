#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, 
                   const std::size_t grid_height
                   )
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Tank Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Tank &tank1, Tank &tank2, std::vector<std::vector<bool>> &map) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render map
  for(int i = 0; i < grid_width; ++i){
    for(int j = 0; j < grid_height; ++j){
      if(map[i][j] == true){
      block.x = i * block.w;
      block.y = j * block.h;
      SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0x00);
      SDL_RenderFillRect(sdl_renderer, &block);
      }
    }
  }

  // Render Tanks
  block.x = static_cast<int>(tank1.pos_x) * block.w;
  block.y = static_cast<int>(tank1.pos_y) * block.h;
  if (tank1.alive) {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block);

  block.x = static_cast<int>(tank2.pos_x) * block.w;
  block.y = static_cast<int>(tank2.pos_y) * block.h;
  if (tank2.alive) {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x7A, 0x00, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block);

  //Render bullets
  for(size_t i = 0; i < tank1.projectiles.size(); i++){
    block.x = static_cast<int>(tank1.projectiles[i]->pos_x) * block.w;
    block.y = static_cast<int>(tank1.projectiles[i]->pos_y) * block.h;
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0x00, 0xFF);
    SDL_RenderFillRect(sdl_renderer, &block);
  }
  for(size_t i = 0; i < tank2.projectiles.size(); i++){
    block.x = static_cast<int>(tank2.projectiles[i]->pos_x) * block.w;
    block.y = static_cast<int>(tank2.projectiles[i]->pos_y) * block.h;
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x7A, 0xCC, 0x00);
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score1, int score2, int fps) {
  std::string title{"Tank 1 Score: " + std::to_string(score1) + "    Tank 2 Score: " + std::to_string(score2) + "    FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}

