
#ifndef __include__clips_controller__
#define __include__clips_controller__

#include "bum.h"

class ClipsController {
public:

  // TODO(suhas): Should work for state of any class.
  static ClipsController* getClipsController(Bum::State state);
  static void setClipsController(Bum::State state, int startClipId,
                                 int endClipId, bool doLoop);

  int getNextClipId(float delta);

private:
  static ClipsController* controllers[Bum::State::STATE_MAX];

  ClipsController(int startClipId, int endClipId, bool doLoop);  // private constructor

  int startClipId, endClipId, currentClipId;
  bool doLoop;
};

#endif /* defined(__include__clips_controller__) */
