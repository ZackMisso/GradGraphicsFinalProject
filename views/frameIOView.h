#ifndef __FRAMEIOVIEW_H__
#define __FRAMEIOVIEW_H__

// This View is used to test Input and Output of the current Frame
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include "../io/bitmap.h"
#include "view.h"

class FrameIOView : public View {
private:
public:
  virtual void initialize();
  virtual void deInitialize();
  virtual void keyboard(int key,int scancode,int action,int mods);
  virtual void display();
};

#endif
