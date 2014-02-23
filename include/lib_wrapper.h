
#ifndef __include__lib_wrapper__
#define __include__lib_wrapper__

class LibWrapper {
public:
  virtual bool init() = 0;
  virtual void render() = 0;
  virtual ~LibWrapper() {}
};

#endif /* defined(__include__lib_wrapper__) */
