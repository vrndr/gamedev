
#ifndef __include__input_handler__
#define __include__input_handler__

#include "lib_wrapper.h"

class InputHandler {

public:
  virtual void init();
  virtual void onTouchDown();
  virtual void handleInputEvents();
  
private:
  LibWrapper *libWrapper;
};

#endif /* defined(__include__input_handler__) */
