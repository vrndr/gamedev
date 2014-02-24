
#ifndef __include__point__
#define __include__point__

// TODO(suhas): Maybe delete this one. Rectangle suffices our needs.
class Point {

public:
  Point(float x, float y);
  float getX();
  float getY();
  
private:
  float x, y;
};

#endif /* defined(__include__point__) */
