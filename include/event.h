
#ifndef __include__event__
#define __include__event__

enum EventType {
  NONE,
  QUIT,
  PAUSE,
  KEY_DOWN,   // Suggestion: Should take implementation specific details out of EventTypes  ~Veerendra
  JUMP,
  BOOST,
  EVENT_MAX    // Last event in enum, only used to define number of items in EventType
               // Always add all the enums before this value
};

class Event {
public:
  Event(EventType type);
  EventType getType();
  
private:
  EventType type;
};

#endif /* defined(__include__event__) */
