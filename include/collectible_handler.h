
#ifndef __include__collectible_injector__
#define __include__collectible_injector__

#include <list>

#include "camera.h"
#include "collectible.h"
#include "stage.h"

// TODO(suhas): Maybe pull out common code between CollectibleHandler and
// ObstacleHander. They seems to be doing same thing.
class CollectibleHandler {

public:
  void initializeObstacles(Stage stage);

  void update(Camera camera);
};

#endif /* defined(__include__collectible_injector__) */
