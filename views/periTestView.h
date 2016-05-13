#ifndef __PERITESTVIEW_H__
#define __PERITESTVIEW_H__

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include "view.h"
#include "../peri/periSystem.h"

class PeriTestView : public View {
private:
  PeriSystemf* periSystem;
  void doPhysicsStep(float dt);
public:
  virtual void initialize();
  virtual void deInitialize();
  virtual void keyboard(int key,int scancode,int action,int mods);
  virtual void mouseClick(int button,int action,int mods);
  virtual void display();
};

#endif
