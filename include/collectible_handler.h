
#ifndef __include__collectible_injector__
#define __include__collectible_injector__

#include <list>

#include "camera.h"
#include "collectible.h"
#include "game_tracker.h"
#include "stage.h"

// TODO(suhas): Maybe pull out common code between CollectibleHandler and
// ObstacleHander. They seems to be doing same thing.
class CollectibleHandler {

public:
  void initializeObstacles(const Stage &stage, GameTracker *gameTracker);

  void update(const Camera &camera);
};

#endif /* defined(__include__collectible_injector__) */
