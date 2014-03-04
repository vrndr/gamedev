
#include "input_handler.h"
#include "wrapper_factory.h"
#include "event_dispatcher.h"

void InputHandler::init() {
  libWrapper = WrapperFactory::getLibWrapper();
}

void InputHandler::onTouchDown() {
  
}

void InputHandler::handleInputEvents() {

  // TODO(suhas): Maybe a while loop, while has event?
  Event *e = libWrapper->getInputEvent();

  switch (e->getType()) {

    case QUIT:
      // Quit game.
      EventDispatcher->dispatchEvent(e);
      break;

    case JUMP:
      EventDispatcher->dispatchEvent(e);
      break;

    default:
      break;
  }

  delete e;
}