
#include "wrapper_factory.h"
#include "sdl_wrapper.h"

LibWrapper* WrapperFactory::sdlWrapper = NULL;

LibWrapper* WrapperFactory::getLibWrapper() {
  switch (USE_LIB) {
    case SDL:
      if (!sdlWrapper) {
        sdlWrapper =  new SdlWrapper();
      }
      return sdlWrapper;
      
    default:
      break;
  }
}