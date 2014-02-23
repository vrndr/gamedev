
#include "wrapper_factory.h"
#include "SDL_wrapper.h"

LibWrapper* WrapperFactory::getLibWrapper() {
  switch (USE_LIB) {
    case SDL:
      return new SdlWrapper();
      break;
      
    default:
      break;
  }
}