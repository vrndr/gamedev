
#ifndef __include__collectible__
#define __include__collectible__

#include "actor.h"

class Collectible : public Actor {

public:
  Collectible(char character);
  char getCharacter();
  void onCollision(Actor *otherActor, Rectangle *overlap);

private:
  // Add collectible type to introduce other types of collectibles than only character.
  char character;
};

#endif /* defined(__include__collectible__) */
