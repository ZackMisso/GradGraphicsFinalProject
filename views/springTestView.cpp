#include "springTestView.h"

void SpringTestView::initialize() {
  one = new PhysicsObjectf();
  two = new PhysicsObjectf();
  one->setPosition(Vec3f(-0.2f,0.0f,0.0f));
  two->setPosition(Vec3f(0.2f,0.0f,0.0f));
  spring = new Springf((void*)one,(void*)two);
  spring->setSpringConstant(1.0f);
  one->getCollisionForces()->add(spring);
  two->getCollisionForces()->add(spring);
}

void SpringTestView::deInitialize() {
  delete one;
  delete two;
  delete spring;
}

void SpringTestView::keyboard(int key,int scancode,int action,int mods) {
  if(key == GLFW_KEY_S && action == GLFW_PRESS) {
    one->setPosition(Vec3f(-0.4f,0.0f,0.0f));
  }
}

void SpringTestView::display() {
  doPhysicsStep(1.0f/60.0f);

  glClearColor(0.0f,0.0f,0.0f,1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glColor3f(1.0,0.0,0.0);

  glBegin(GL_QUADS);
  glVertex2f(one->getPosition()[0]-0.1f,0.1f);
  glVertex2f(one->getPosition()[0]-0.1f,-0.1f);
  glVertex2f(one->getPosition()[0],-0.1f);
  glVertex2f(one->getPosition()[0],0.1f);

  glVertex2f(two->getPosition()[0]+0.1f,0.1f);
  glVertex2f(two->getPosition()[0]+0.1f,-0.1f);
  glVertex2f(two->getPosition()[0],-0.1f);
  glVertex2f(two->getPosition()[0],0.1f);
  glEnd();

  glColor3f(0.0f,0.0f,1.0f);
  spring->render();
}

void SpringTestView::doPhysicsStep(float dt) {
  spring->setCurrentPositions();
  spring->calculateCurrentRestPosition();
  spring->calculateForce();
  spring->calculatePotential();
  one->performPhysicsStep(dt);
  //two->performPhysicsStep(dt);
}
