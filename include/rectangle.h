
#ifndef __include__rectangle__
#define __include__rectangle__

class Rectangle {

public:
  Rectangle(float x, float y, float w, float h);
  float getX();
  float getY();
  float getWidth();
  float getHeight();

private:
  float x, y, w, h;
};

#endif // defined(__include__rectangle__)
