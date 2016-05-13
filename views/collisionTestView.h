#ifndef __COLLISIONTESTVIEW_H__
#define __COLLISIONTESTVIEW_H__

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include "view.h"
#include "../physics/physicsObject.h"
#include "../geometry/rectPrism.h"

class CollisionTestView : public View {
private:
  PhysicsObjectf* one;
  PhysicsObjectf* two;
  RectPrismf* onePr;
  RectPrismf* twoPr;
  Springf* collisionSpring;
  bool isWireFrame;
  int cnt;
  void doPhysicsStep(float dt);
public:
  virtual void initialize();
  virtual void deInitialize();
  virtual void keyboard(int key,int scancode,int action,int mods);
  virtual void mouseClick(int button,int action,int mods);
  virtual void display();
  virtual void headless();
};

#endif
