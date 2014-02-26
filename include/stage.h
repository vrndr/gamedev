
#ifndef __include__stage__
#define __include__stage__

#include <list>

#include "actor.h"

class Stage {
public:
  void addActor(Actor *actor);
  void removeActor(Actor *actor);
  std::list<Actor *> getAllActors() const;

private:
  std::list<Actor *> actors;
};

#endif /* defined(__include__stage__) */

