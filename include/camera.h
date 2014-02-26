#ifndef __include__camera__
#define __include__camera__

#include "lib_wrapper.h"
#include "stage.h"

class Camera {

public:
  void init();
  void render(const Stage &stage);
  void update();
  void followActor(Actor *actor);
  Rectangle getCameraPosition() const;

private:
  Rectangle cameraPosition;
  LibWrapper *libWrapper;
  Actor *actorToFollow;

  void renderActor(Actor *actor);
};

#endif /* defined(__include__camera__) */
