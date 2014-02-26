
#ifndef __include__sdl_wrapper__
#define __include__sdl_wrapper__

#include <vector>

#include "lib_wrapper.h"
#include "SDL.h"

class SdlWrapper : public LibWrapper {
  SDL_Window *window;
  SDL_Renderer *renderer;
  std::vector<SDL_Texture *> textures;

public:

  SdlWrapper():window(NULL), renderer(NULL) {}  // Default constructor

  ~SdlWrapper() {                               // Default destructor
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
  }

  bool init();
  void startRendering();
  void render(const Renderable &renderable, const Rectangle &position);
  void finishRendering();

  // Creates texture and returns textureId, that can be referrenced later to
  // render the texture created.
  int createTexture(const std::string &fileName);

  Event* getInputEvent();
};

#endif /* defined(__include__sdl_wrapper__) */
