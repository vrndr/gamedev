
#ifndef __include__wrapper_factory__
#define __include__wrapper_factory__

#include "lib_wrapper.h"

class WrapperFactory {
public:
  LibWrapper* getLibWrapper();

private:
  enum GameLib {
    SDL
  };

  static const GameLib USE_LIB = SDL;
};

#endif /* defined(__include__wrapper_factory__) */
