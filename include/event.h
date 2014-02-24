
#ifndef __include__event__
#define __include__event__

enum EventType {
  NONE,
  QUIT,
  KEY_DOWN,
};

class Event {
public:
  Event(EventType type);
  EventType getType();
  
private:
  EventType type;
};

#endif /* defined(__include__event__) */
