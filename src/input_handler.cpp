
#include "input_handler.h"
#include "wrapper_factory.h"

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
      break;

    // Handle all events;

    default:
      break;
  }

  delete e;
}