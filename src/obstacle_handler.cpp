
#include "obstacle_handler.h"

void ObstacleHandler::initializeCollectibles(Stage *stage) {
  this->stage = stage;
  last_obstacle_position = 0;

  // This is the ground on which our bum runs.

  // Should not be an visible obstacle. Should be
  // invisble object. Ground will be part of background.
  ground = new Obstacle();
  // TODO(suhas): Move these constants to GameConfig.
  ground->setX(0);
  ground->setY(400);
  ground->setWidth(800);
  ground->setHeight(80);
  stage->addActor(ground);
}

void ObstacleHandler::update(const Camera &camera) {

  /******* Only for testing. ******/
  float cameraX = camera.getCameraPosition().getX();
  if (cameraX > (last_obstacle_position)) {
    Obstacle *obstacle = new Obstacle();
    obstacle->setX(cameraX + 800);
    obstacle->setY(340);
    obstacle->setWidth(80);
    obstacle->setHeight(80);
    stage->addActor(obstacle);
    last_obstacle_position = obstacle->getX();
  }
  /******* Only for testing. ******/
  // Keep extending ground. (an invisible obstacle).
  ground->setWidth(cameraX + 800);

}
