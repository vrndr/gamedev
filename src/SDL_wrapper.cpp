#include <iostream>
#include "sdl_wrapper.h"

using namespace std ;

bool SdlWrapper::init() {

  // TODO (Veerendra): return meaningful error values
  int quit = false ;

  if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
    cout << SDL_GetError() << endl;
    return false;
  }

  window = SDL_CreateWindow("SpellingBum", SDL_WINDOWPOS_CENTERED, 
    SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == nullptr){
    cout << SDL_GetError() << endl;
    return false;
  }
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED 
    | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == nullptr){
    cout << SDL_GetError() << endl;
    return false;
  }

  SDL_RenderClear(renderer);
  return true;
}

void SdlWrapper::render() {

}
