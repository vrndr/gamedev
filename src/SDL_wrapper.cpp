#include <iostream>

#include "game_config.h"
#include "sdl_wrapper.h"

using namespace std ;

bool SdlWrapper::init() {

  // TODO (Veerendra): return meaningful error values

  if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
    cout << SDL_GetError() << endl;
    return false;
  }

  window = SDL_CreateWindow("SpellingBum", SDL_WINDOWPOS_CENTERED, 
      SDL_WINDOWPOS_CENTERED, GameConfig::screenWidth, GameConfig::screenHeight,
      SDL_WINDOW_SHOWN);
  if (window == nullptr){
    cout << SDL_GetError() << endl;
    return false;
  }
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
      SDL_RENDERER_PRESENTVSYNC);
  if (renderer == nullptr){
    cout << SDL_GetError() << endl;
    return false;
  }

  SDL_RenderClear(renderer);
  return true;
}

void SdlWrapper::render() {

}

Event* SdlWrapper::getInputEvent() {
  Event *e;
  SDL_Event sdlEvent;
  SDL_PollEvent(&sdlEvent);

  switch (sdlEvent.type) {

    case SDL_QUIT:
      e = new Event(QUIT);
      break;

    case SDL_KEYDOWN:
      e = new Event(KEY_DOWN);
      // Set other event data like key type
      break;

    // Handle other events like touch.
    default:
      e = new Event(NONE);
  }

  return e;
}