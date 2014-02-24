#ifndef __include__camera__
#define __include__camera__

#include "lib_wrapper.h"
#include "stage.h"

class Camera {

public:
  void init();
  void render(Stage stage);

private:
  LibWrapper *libWrapper;
  void renderActor(Actor actor);
};

#endif /* defined(__include__camera__) */
