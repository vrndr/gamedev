
#ifndef __include__wrapper_factory__
#define __include__wrapper_factory__

#include <iostream>

#include "lib_wrapper.h"

class WrapperFactory {
public:
  static LibWrapper* getLibWrapper();

private:
  static LibWrapper* sdlWrapper;

  enum GameLib {
    SDL
  };

  static const GameLib USE_LIB = SDL;
};

#endif /* defined(__include__wrapper_factory__) */
