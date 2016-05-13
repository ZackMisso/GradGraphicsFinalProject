/*#ifndef __FRACTUREVIEW_H__
#define __FRACTUREVIEW_H__

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include "view.h"
#include "../peri/periSystem.h"
#include "../physics/dummyObject.h"
#include "../dataStructures/array.h"

class FractureView : public View {
private:
  PeriSystemd* periSystem;
  //PhysicsObjectd* collideObject;
  //Array<Springd*>* collisionSprings;
  //Array<DummyObjectd*>* collisionObjects;
  int cnt;
  void doPhysicsStep(double dt);
public:
  virtual void initialize();
  virtual void deInitialize();
  virtual void keyboard(int key,int scancode,int action,int mods);
  virtual void mouseClick(int button,int action,int mods);
  virtual void display();
};

#endif*/