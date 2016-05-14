#include "fractureTwo.h"
#include "../geometry/bbox.h"
#include "../geometry/voxelizer.h"
#include "../geometry/rectPrism.h"
#include "../physics/collisionMethods.h"
//#include "../peri/pointMass.h"
#include <iostream>

using namespace std;

void FractureTwo::initialize() {
  BBoxd box = BBoxd(Vec3d(-0.5,-0.3,-0.05),Vec3d(1.0,1.0,0.06));
  cout << "Voxelizing Box" << endl;
  Array<Voxeld*>* voxelMesh = Voxelizer::getInstance()->voxelizeBBox(box,0.03);
  cout << "Voxelized Box" << endl;
  //Array<Voxelf*>* voxelMesh = Voxelizer::getInstance()->voxelizeBBox(box,0.5f);
  cout << "Voxel Mesh Size: " << voxelMesh->getSize() << endl;
  cout << "Creating Peri System" << endl;
  periSystem = new PeriSystemd();
  periSystem->setPointMassR(0.05);
  periSystem->setPointMassM(1.0);
  periSystem->setPointMassH(0.21);
  //periSystem->setPointMassH(0.31);
  periSystem->setSpringConstant(10.0);
  periSystem->setSpringDamp(2.0);
  periSystem->setSpringBreak(0.05);
  drawSprings = true;
  //periSystem->setSpringConstant(60.0);
  //periSystem->setSpringDamp(5.0);
  //periSystem->setSpringConstant(1.0);
  //periSystem->setSpringDamp(0.1);
  cnt = 0;
  //periSystem->setSpringBreak(10.0);
  cout << "Converting Voxels To Point Masses" << endl;
  periSystem->convertVoxelsToPoints(voxelMesh);
  cout << "Number Of Springs: " << periSystem->getSprings()->getSize() << endl;
  cout << "Finished Conversion" << endl;
  //for(int i=0;i<periSystem->getPointMasses()->getSize();i++) {
  //  //periSystem->getPointMasses()->get(i)->getExternelForces()->add(new Vec3d(0.0,-5.0,0.0));
  //  periSystem->getPointMasses()->get(i)->getExternelForces()->add(new Vec3d(0.0,-4.0,0.0));
  //  //periSystem->getPointMasses()->get(i)->getExternelForces()->add(new Vec3f(0.0f,-1.0f,0.0f));
  //}

  //periSystem->getPointMasses()->get(54)->getExternelForces()->add(new Vec3d(0.0,0.0,-800.0));
  //periSystem->getPointMasses()->get(45)->getExternelForces()->add(new Vec3d(0.0,0.0,-800.0));
  //periSystem->getPointMasses()->get(54)->getExternelForces()->add(new Vec3d(0.0,0.0,-800.0));
  //periSystem->getPointMasses()->get(55)->getExternelForces()->add(new Vec3d(0.0,0.0,-800.0));

  for(int i=7;i<11;i++) {
    for(int j=7;j<11;j++) {
      periSystem->getPointMasses()->get(i*j+j)->getExternelForces()->add(new Vec3d(0.0,0.0,-10.0));
    }
  }
}

void FractureTwo::deInitialize() {
  delete periSystem;
}

void FractureTwo::keyboard(int key,int scancode,int action,int mods) {
  if(key == GLFW_KEY_B && action == GLFW_PRESS) {
    //PointMassd* one = periSystem->getPointMasses()->get(0);
    //one->setPosition(Vec3d(-0.8,-0.05,0.0));
    drawSprings = !drawSprings;
  }
}

void FractureTwo::mouseClick(int button,int action,int mods) {
  // to be implemented
}

void FractureTwo::display() {
  //cout << "Displaying" << endl;
  //cout << "Frame: " << (cnt++) / 10 << endl;
  //cout << "Frame: " << (cnt++) << endl;
  doPhysicsStep(1.0/160.0);
  //cout << "Finished Physics" << endl;
  //doPhysicsStep(1.0f/600.0f);
  //cout << "Exit Physics Step" << endl;

  glClearColor(0.0f,0.0f,0.0f,1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(35.0,1.0,.1,10);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(2.0,2.0,-6.0,0.0,0.0,0.0,0.0,1.0,0.0);
  //cout << "Rendering Peri" << endl;
  glColor3f(1.0f,0.0f,0.0f);
  periSystem->render(SOLID,drawSprings);
  glColor3f(0.0f,0.0f,0.0f);
  //cout << "Rendering Box" << endl;
  //collideObject->render(WIREFRAME);
  //cout << "Display Done" << endl;
  glColor3f(0.0f,1.0f,0.0f);
  //PointMassf* one = periSystem->getPointMasses()->get(0);
  for(int i=7;i<11;i++) {
    for(int j=7;j<11;j++) {
      periSystem->getPointMasses()->get(i*j+j)->render(WIREFRAME);
    }
  }
  //periSystem->getPointMasses()->get(44)->render(WIREFRAME);
  //periSystem->getPointMasses()->get(45)->render(WIREFRAME);
  //periSystem->getPointMasses()->get(54)->render(WIREFRAME);
  //periSystem->getPointMasses()->get(55)->render(WIREFRAME);
}

void FractureTwo::doPhysicsStep(double dt) {
  periSystem->performPhysicsStep(dt);
}
