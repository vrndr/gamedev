
#ifndef __include__rectangle__
#define __include__rectangle__

class Rectangle {

public:
  Rectangle(float x = 0, float y = 0, float w = 0, float h = 0);
  float getX() const;
  float getY() const;
  float getWidth() const;
  float getHeight() const;

  void set(float x, float y, float w, float h);

private:
  float x, y, w, h;
};

#endif /* defined(__include__rectangle__) */
