#ifndef __COLLISIONTESTDOUBLEVIEW_H__
#define __COLLISIONTESTDOUBLEVIEW_H__

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include "view.h"
#include "../physics/physicsObject.h"
#include "../geometry/rectPrism.h"

class CollisionTestDoubleView : public View {
private:
  PhysicsObjectd* one;
  PhysicsObjectd* two;
  RectPrismd* onePr;
  RectPrismd* twoPr;
  Springd* collisionSpring;
  bool isWireFrame;
  int cnt;
  void doPhysicsStep(double dt);
public:
  virtual void initialize();
  virtual void deInitialize();
  virtual void keyboard(int key,int scancode,int action,int mods);
  virtual void mouseClick(int button,int action,int mods);
  virtual void display();
  virtual void headless();
};

#endif
