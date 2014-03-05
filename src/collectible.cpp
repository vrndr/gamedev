
#include "collectible.h"
#include "event_dispatcher.h"

Collectible::Collectible(char character) {
  std::string text(1, character);
  renderable = Renderable::Builder()
      .setRenderType(RenderType::RENDER_TEXT)
      .setText(text)
      .build();

  this->character = character;
  setActorStyle(NON_MOVING_COLLIDABLE_NON_BLOCKING);
}

char Collectible::getCharacter() {
  return character;
}

void Collectible::onCollision(Actor *otherActor, Rectangle *overlap) {
  Event *e = new Event(EventType::OBJECT_COLLECTED);
  Event::EventData *data = e->getEventData();
  data->collectedCharacter = character;
  EventDispatcher->dispatchEvent(e);

  setActorStyle(NON_MOVING_NON_COLLIDABLE);
}