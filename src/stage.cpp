
#include <iostream>

#include "stage.h"

void Stage::addActor(Actor actor) {
  actors.push_back(actor);
}

void Stage::removeActor(Actor actor) {
  
}

std::list<Actor> Stage::getAllActors() {
  return actors;
}