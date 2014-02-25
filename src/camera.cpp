
#include "camera.h"
#include "game_config.h"
#include "wrapper_factory.h"

void Camera::init() {
  libWrapper = WrapperFactory::getLibWrapper();
  actorToFollow = NULL;
  cameraPosition.set(0 , 0, GameConfig::screenWidth, GameConfig::screenHeight);
}

void Camera::render(const Stage &stage) {
  std::list<Actor> actors = stage.getAllActors();
  for (std::list<Actor>::iterator actor = actors.begin();
      actor != actors.end(); actor++) {
    renderActor(*actor);
  }
}

void Camera::renderActor(const Actor &actor) {
  Rectangle actorPosition = Rectangle(actor.getX(), actor.getY(),
      actor.getWidth(), actor.getHeight());

  if (actor.isStaticActor()) {
    // Static position. Always maintain the actor position.
  } else {
    // Determine position of actor.
  }

  // Render actor at actorPosition.
  // TODO(suhas): Actor class should have the info about how it should be rendered.

  libWrapper->render(); // Pass more info here.
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
}