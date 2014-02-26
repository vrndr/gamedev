#ifndef __include__bum__
#define __include__bum__

#include "actor.h"

class Bum : public Actor {
public:
  Bum();
  void update(float delta);
};

#endif /* defined(__include__bum__) */
