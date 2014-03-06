
#include "obstacle.h"
#include "renderable_factory.h"

Obstacle::Obstacle() {
  renderable = RenderableFactory->getObstacleRenderable();
  setActorStyle(NON_MOVING_COLLIDABLE_BLOCKING);
}
