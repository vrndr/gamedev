#ifndef __include__sdl_wrapper__
#define __include__sdl_wrapper__

#include "lib_wrapper.h"

class SdlWrapper : public LibWrapper {
public:
  bool init();
  void render();
};

#endif /* defined(__include__sdl_wrapper__) */
