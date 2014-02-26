
#include "obstacle_handler.h"

void ObstacleHandler::initializeCollectibles(Stage *stage) {
  this->stage = stage;
  last_obstacle_position = 0;
}

void ObstacleHandler::update(const Camera &camera) {

  /******* Only for testing. ******/
  float cameraX = camera.getCameraPosition().getX();
  if (cameraX > (last_obstacle_position)) {
    Obstacle *obstacle = new Obstacle();
    obstacle->setX(cameraX + 800);
    obstacle->setY(300);
    obstacle->setWidth(80);
    obstacle->setHeight(80);
    stage->addActor(obstacle);
    last_obstacle_position = obstacle->getX();
  }

  /******* Only for testing. ******/
}
