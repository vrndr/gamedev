#ifndef __include__event_dispatcher__
#define __include__event_dispatcher__

#include <list>

#include "base_entity.h"

// Event dispatcher class that will dispatch events to classes 
// registered for the event

class __EventDispatcher
{
private:
  __EventDispatcher() {}   // private constructor
  std::list<BaseEntity*> registeredHandlers[EVENT_MAX];

public:
  static __EventDispatcher* GetInstance()
  {
    static __EventDispatcher instance ;
    return &instance ;
  }

  int registerEventHandler( BaseEntity* entity, EventType eType );
  void dispatchEvent(Event* e);

}; 

#define EventDispatcher __EventDispatcher::GetInstance()

#endif // __include__event_dispatcher__