
#ifndef __include__lib_wrapper__
#define __include__lib_wrapper__

#include <string>

#include "event.h"
#include "rectangle.h"
#include "renderable.h"

class LibWrapper {

public:
  virtual bool init() = 0;
  virtual void startRendering() = 0;
  virtual void render(const Renderable &renderable, const Rectangle &position) = 0;
  virtual void finishRendering() = 0;
  virtual Event* getInputEvent() = 0;

  // Creates texture and returns textureId, that can be referrenced later to
  // render the texture created.
  virtual int createTexture(const std::string &fileName) = 0;

  virtual ~LibWrapper() {}
};

#endif /* defined(__include__lib_wrapper__) */
