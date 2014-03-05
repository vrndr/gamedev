
#ifndef __include__spell_display__
#define __include__spell_display__

#include "actor.h"

// Bad class name. Rename.
// It should be a Word as Actor which may have character which can share the
// sprite sheet.
class GameWordCharacter : public Actor {

public:
  GameWordCharacter(char c);
  char getCharacter();
  bool isHidden();
  void markFound();

private:
  char character;
  bool hidden;
};

#endif /* defined(__include__spell_display__) */
