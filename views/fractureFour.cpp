#include "fractureFour.h"
#include "../geometry/bbox.h"
#include "../geometry/voxelizer.h"
#include "../geometry/rectPrism.h"
#include "../physics/collisionMethods.h"
//#include "../peri/pointMass.h"
#include <iostream>

using namespace std;

void FractureFour::initialize() {
  BBoxd box = BBoxd(Vec3d(-0.5,-0.3,-0.05),Vec3d(1.0,1.0,0.02));
  cout << "Voxelizing Box" << endl;
  Array<Voxeld*>* voxelMesh = Voxelizer::getInstance()->voxelizeBBox(box,0.01);
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
  periSystem->setSpringBreak(0.01);
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

  for(int i=20;i<30;i++) {
    for(int j=20;j<30;j++) {
      periSystem->getPointMasses()->get(i*50+j)->getExternelForces()->add(new Vec3d(0.0,0.0,-80.0));
    }
  }
}

void FractureFour::deInitialize() {
  delete periSystem;
}

void FractureFour::keyboard(int key,int scancode,int action,int mods) {
  if(key == GLFW_KEY_B && action == GLFW_PRESS) {
    //PointMassd* one = periSystem->getPointMasses()->get(0);
    //one->setPosition(Vec3d(-0.8,-0.05,0.0));
    drawSprings = !drawSprings;
  }
}

void FractureFour::mouseClick(int button,int action,int mods) {
  // to be implemented
}

void FractureFour::display() {
  //cout << "Displaying" << endl;
  //cout << "Frame: " << (cnt++) / 10 << endl;
  //cout << "Frame: " << (cnt++) << endl;
  doPhysicsStep(1.0/400.0);
  //cout << "Finished Physics" << endl;
  //doPhysicsStep(1.0f/600.0f);
  //cout << "Exit Physics Step" << endl;

  glClearColor(0.0f,0.0f,0.0f,1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  //cout << "Rendering Peri" << endl;
  glColor3f(1.0f,0.0f,0.0f);
  periSystem->render(SOLID,drawSprings);
  glColor3f(0.0f,0.0f,0.0f);
  //cout << "Rendering Box" << endl;
  //collideObject->render(WIREFRAME);
  //cout << "Display Done" << endl;
  glColor3f(0.0f,1.0f,0.0f);
  //PointMassf* one = periSystem->getPointMasses()->get(0);
  for(int i=20;i<30;i++) {
    for(int j=20;j<30;j++) {
      periSystem->getPointMasses()->get(i*50+j)->render(WIREFRAME);
    }
  }
  //periSystem->getPointMasses()->get(44)->render(WIREFRAME);
  //periSystem->getPointMasses()->get(45)->render(WIREFRAME);
  //periSystem->getPointMasses()->get(54)->render(WIREFRAME);
  //periSystem->getPointMasses()->get(55)->render(WIREFRAME);
}

void FractureFour::doPhysicsStep(double dt) {
  periSystem->performPhysicsStep(dt);
}
