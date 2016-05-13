#include "springTestViewDouble.h"

void SpringTestViewDouble::initialize() {
  one = new PhysicsObjectd();
  two = new PhysicsObjectd();
  one->setPosition(Vec3d(-0.2,0.0,0.0));
  two->setPosition(Vec3d(0.2,0.0,0.0));
  spring = new Springd((void*)one,(void*)two);
  spring->setSpringConstant(10.0);
  spring->setDampConstant(5.0);
  spring->setIsPeriSpring(true);
  one->getCollisionForces()->add(spring);
  two->getCollisionForces()->add(spring);
  cout << "Initialized" << endl;
}

void SpringTestViewDouble::deInitialize() {
  delete one;
  delete two;
  delete spring;
}

void SpringTestViewDouble::keyboard(int key,int scancode,int action,int mods) {
  if(key == GLFW_KEY_S && action == GLFW_PRESS) {
    one->setPosition(Vec3d(-0.4,0.0,0.0));
  }
}

void SpringTestViewDouble::display() {
  cout << "Displaying" << endl;
  doPhysicsStep(1.0/60.0);
  cout << "Out Of Physics" << endl;

  glClearColor(0.0f,0.0f,0.0f,1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glColor3f(1.0,0.0,0.0);

  glBegin(GL_QUADS);
  glVertex2f(one->getPosition()[0]-0.1,0.1);
  glVertex2f(one->getPosition()[0]-0.1,-0.1);
  glVertex2f(one->getPosition()[0],-0.1);
  glVertex2f(one->getPosition()[0],0.1);

  glVertex2f(two->getPosition()[0]+0.1,0.1);
  glVertex2f(two->getPosition()[0]+0.1,-0.1);
  glVertex2f(two->getPosition()[0],-0.1);
  glVertex2f(two->getPosition()[0],0.1);
  glEnd();

  glColor3f(0.0f,0.0f,1.0f);
  spring->render(SOLID);
}

void SpringTestViewDouble::doPhysicsStep(double dt) {
  cout << "Setting the Positions" << endl;
  spring->setCurrentPositions();
  cout << "Calculating REst Positions" << endl;
  spring->calculateCurrentRestPosition();
  cout << "Calculating Forces" << endl;
  spring->calculateForce();
  cout << "Calculating Potential" << endl;
  spring->calculatePotential();
  cout << "Performing Physics Step One" << endl;
  one->performPhysicsStep(dt);
  cout << "Performing Physics Step Two" << endl;
  //two->performPhysicsStep(dt);
}
