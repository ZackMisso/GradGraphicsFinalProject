#ifndef __COLLISIONTESTVIEW_H__
#define __COLLISIONTESTVIEW_H__

#include "view.h"
#include "../physics/physicsObject.h"

class CollisionTestView : public View {
private:
  PhysicsObjectf* one;
  PhysicsObjectf* two;
  Springf* collisionSpring;
  void doPhysicsStep(float dt);
public:
  virtual void initialize();
  virtual void deInitialize();
  virtual void keyboard(int key,int scancode,int action,int mods);
  virtual void mouseClick(int button,int action,int mods);
  virtual void display();
};

#endif
