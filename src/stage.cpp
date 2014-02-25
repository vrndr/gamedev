
#include <iostream>

#include "stage.h"

void Stage::addActor(const Actor &actor) {
  actors.push_back(actor);
}

void Stage::removeActor(const Actor &actor) {
  
}

std::list<Actor> Stage::getAllActors() const {
  return actors;
}