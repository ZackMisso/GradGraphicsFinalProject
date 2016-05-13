#ifndef __SPRINGTESTVIEWDOUBLE_H__
#define __SPRINGTESTVIEWDOUBLE_H__

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include "view.h"
#include "../physics/physicsObject.h"
#include "../physics/spring.h"

class SpringTestViewDouble : public View {
private:
  PhysicsObjectd* one;
  PhysicsObjectd* two;
  Springd* spring;
  void doPhysicsStep(double dt);
public:
  virtual void initialize();
  virtual void deInitialize();
  virtual void keyboard(int key,int scancode,int action,int mods);
  virtual void display();
};

#endif
