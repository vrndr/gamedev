
#include "clips_controller.h"

ClipsController* ClipsController::controllers[Bum::State::STATE_MAX];

ClipsController::ClipsController(int startClipId, int endClipId, bool doLoop) {
  this->startClipId = startClipId;
  this->endClipId = endClipId;
  this->doLoop = doLoop;

  this->currentClipId = startClipId;
}

ClipsController* ClipsController::getClipsController(Bum::State state) {
  return controllers[state];
}

void ClipsController::setClipsController(Bum::State state, int startClipId,
                                         int endClipId, bool doLoop) {
  controllers[state] = new ClipsController(startClipId, endClipId, doLoop);
}

int ClipsController::getNextClipId(float delta) {

  /********* code for testing only *****************/
  /********* just to slow down the clip speed ******/
  static int i = 0;
  i++;
  if (i < 8) {
    return currentClipId;
  }
  i = 0;
  /********* just to slow down the clip speed ******/
  /********* code for testing only *****************/

  // TODO(suhas): Next clip id should consider delta, so that we don't change clips too fast.
  // Even better - should have clip speed as part of this class.
  currentClipId++;
  if (currentClipId > endClipId) {
    currentClipId = startClipId;
  }
  return currentClipId;
}
