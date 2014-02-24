
#ifndef __include__obstacle_injector__
#define __include__obstacle_injector__

#include <list>

#include "camera.h"
#include "obstacle.h"
#include "stage.h"

// TODO(suhas): Maybe pull out common code between CollectibleHandler and
// ObstacleHander. They seems to be doing same thing.
class ObstacleHandler {
  
public:
  void initializeCollectibles(Stage stage);

  void update(Camera camera);
};

#endif /* defined(__include__obstacle_injector__) */
