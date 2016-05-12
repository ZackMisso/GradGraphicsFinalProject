#include "springTestView.h"

void SpringTestView::initialize() {
  one = new PhysicsObjectf();
  two = new PhysicsObjectf();
  one->setPosition(Vec3f(-0.4f,0.0f,0.0f));
  two->setPosition(Vec3f(-0.4f,0.0f,0.0f));
  spring = new Springf((void*)one,(void*)two);
  one->collisionForces->add(spring);
  two->collisionForces->add(spring);
}

void SpringTestView::deInitialize() {
  delete one;
  delete two;
  delete spring;
}

void SpringTestView::keyboard(int key,int scancode,int action,int mods) {
  // to be implemented
}

void SpringTestView::display() {
  // to be implemented
}
