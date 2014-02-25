#ifndef  __include__base_entity__
#define __include__base_entity__

#include "event.h"

// This class is the base class of all entities in the game
// It provides event handling capability to all derived classes
class BaseEntity {
public:
  virtual void handleEvent(Event* e) {}  ;
};


#endif // __include__base_entity__