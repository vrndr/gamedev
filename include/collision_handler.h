
#ifndef __include__collision_handler__
#define __include__collision_handler__

#include "stage.h"

class CollisionHandler {
  
public:
  void init();

  void checkCollisions(const Stage &stage);
};

#endif /* defined(__include__collision_handler__) */
