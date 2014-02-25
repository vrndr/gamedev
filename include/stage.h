
#ifndef __include__stage__
#define __include__stage__

#include <list>

#include "actor.h"

class Stage {
public:
  void addActor(const Actor &actor);
  void removeActor(const Actor &actor);
  std::list<Actor> getAllActors() const;

private:
  std::list<Actor> actors;
};

#endif /* defined(__include__stage__) */

