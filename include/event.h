
#ifndef __include__event__
#define __include__event__

enum EventType {
  NONE,
  QUIT,
  PAUSE,
  JUMP,
  BOOST,
  OBJECT_COLLECTED,
  GAME_OVER,
  EVENT_MAX    // Last event in enum, only used to define number of items in EventType
               // Always add all the enums before this value
};

class Event {
public:
  Event(EventType type);
  EventType getType();

  class EventData {
  public:
    // For event OBJECT_COLLECTED
    char collectedCharacter;
  };

  EventData* getEventData();
  
private:
  EventType type;
  EventData eventData;
};

#endif /* defined(__include__event__) */
