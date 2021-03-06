
#include "camera.h"
#include "game_config.h"
#include "wrapper_factory.h"

void Camera::init() {
  libWrapper = WrapperFactory::getLibWrapper();
  actorToFollow = NULL;
  cameraPosition.set(0, 0, GameConfig::screenWidth, GameConfig::screenHeight);
}

void Camera::render(const Stage &stage) {
  std::list<Actor *> actors = stage.getAllActors();
  libWrapper->startRendering();
  for (std::list<Actor *>::iterator actor = actors.begin();
      actor != actors.end(); actor++) {
    renderActor(*actor);
  }
  libWrapper->finishRendering();
}

void Camera::renderActor(Actor *actor) {
  Rectangle actorPosition = Rectangle(actor->getX(), actor->getY(),
      actor->getWidth(), actor->getHeight());

  if (actor->isActorActive()) {
    // Determine position of actor.
    actorPosition.setX(actorPosition.getX() - cameraPosition.getX());
  } else {
    // Static position. Always maintain the actor position.
  }

  Renderable renderable = actor->getRenderable();

  // Render actor at actorPosition.
  // TODO(suhas): Actor class should have the info about how it should be rendered.

  libWrapper->render(renderable, actorPosition);
}

void Camera::followActor(Actor *actor) {
  actorToFollow = actor;
}

void Camera::update() {
  if (!actorToFollow) {
    return;
  }
  Rectangle actorPosition = actorToFollow->getPosition();

  // Update camera position as per actorPosition.
  cameraPosition.setX(actorPosition.getX() - GameConfig::bumXPositionOnScreen);
}

Rectangle Camera::getCameraPosition() const {
  return cameraPosition;
}
