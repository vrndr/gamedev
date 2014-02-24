#ifndef __include__sdl_wrapper__
#define __include__sdl_wrapper__

#include "lib_wrapper.h"
#include "SDL.h"

class SdlWrapper : public LibWrapper {
  SDL_Window *window;
  SDL_Renderer *renderer;
  static const int SCREEN_WIDTH = 640 ;
  static const int SCREEN_HEIGHT = 480 ;

public:

  SdlWrapper():window(NULL), renderer(NULL) {}  // Default constructor

  ~SdlWrapper() {                               // Default destructor
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
  }

  bool init();
  void render();
};

#endif /* defined(__include__sdl_wrapper__) */
