#ifndef __SPRINGTESTVIEW_H__
#define __SPRINGTESTVIEW_H__

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include "view.h"
#include "../physics/physicsObject.h"
#include "../physics/spring.h"

class SpringTestView : public View {
private:
  PhysicsObjectf* one;
  PhysicsObjectf* two;
  Springf* spring;
  void doPhysicsStep(float dt);
public:
  virtual void initialize();
  virtual void deInitialize();
  virtual void keyboard(int key,int scancode,int action,int mods);
  virtual void display();
};

#endif
