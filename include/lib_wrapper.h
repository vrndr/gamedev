
#ifndef __include__lib_wrapper__
#define __include__lib_wrapper__

#include "event.h"

class LibWrapper {

public:
  virtual bool init() = 0;
  virtual void render() = 0;
  virtual Event* getInputEvent() = 0;
  virtual ~LibWrapper() {}
};

#endif /* defined(__include__lib_wrapper__) */
