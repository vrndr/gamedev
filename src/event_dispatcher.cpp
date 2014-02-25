#include "event_dispatcher.h"

int __EventDispatcher::registerEventHandler( BaseEntity* entity, EventType eType )
{

  if( entity != nullptr )
  {
    registeredHandlers[eType].push_back(entity);
    return 0 ;
  }

  return 1 ;
}

void __EventDispatcher::dispatchEvent(Event* e)
{
  if( e != nullptr )
  {
    std::list<BaseEntity*>::iterator iter ;

    for( iter = registeredHandlers[e->getType()].begin() ; 
         iter != registeredHandlers[e->getType()].end() ;
         iter++ )
    {
      (*iter)->handleEvent(e);
    }
  }  
}
