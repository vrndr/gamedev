
#include "event.h"

Event::Event(EventType type) {
  this->type = type;
}

EventType Event::getType() {
  return type;
}

