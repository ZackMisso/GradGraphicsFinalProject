#ifndef __COLLISIONTESTVIEW_H__
#define __COLLISIONTESTVIEW_H__

#include "view.h"
#include "../physics/physicsEngine.h"

class CollisionTestView : public View {
private:
  PhysicsEngine* engine;
  PhysicsWorld* worldRef;
  string fileName;
public:
  virtual void initialize();
  virtual void deInitialize();
  virtual void keyboard(int key,int scancode,int action,int mods);
  virtual void mouseMove(double x,double y);
  virtual void mouseClick(int button,int action,int mods);
  virtual void display();
  virtual void headless();
};

#endif
