#include "periTestView.h"
#include "../geometry/bbox.h"
#include "../geometry/voxelizer.h"
#include <iostream>

using namespace std;

void PeriTestView::initialize() {
  BBoxf box = BBoxf(Vec3f(-0.5f,-0.5f,-0.05f),Vec3f(1.0f,1.0f,0.1f));
  Array<Voxelf*>* voxelMesh = Voxelizer::getInstance()->voxelizeBBox(box,0.05f);
  cout << "Voxel Mesh Size: " << voxelMesh->getSize() << endl;
  periSystem = new PeriSystemf();
  periSystem->setPointMassR(0.05f);
  periSystem->setPointMassM(1.0f);
  periSystem->setPointMassH(0.21f);
  periSystem->convertVoxelsToPoints(voxelMesh);
  cout << "Spring Size: " << periSystem->getSprings()->getSize() << endl;
  cout << "First Ones Springs: " << periSystem->getPointMasses()->get(0)->getNeighborhood()->getSize() << endl;
}

void PeriTestView::deInitialize() {
  delete periSystem;
}

void PeriTestView::keyboard(int key,int scancode,int action,int mods) {
  // to be implementd
}

void PeriTestView::mouseClick(int button,int action,int mods) {
  // to be implemented
}

void PeriTestView::display() {
  doPhysicsStep(1.0f/60.0f);

  glClearColor(0.0f,0.0f,0.0f,1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  periSystem->render(WIREFRAME,true);

  glColor3f(0.0f,1.0f,0.0f);
  PointMassf* one = periSystem->getPointMasses()->get(0);
  for(int i=0;i<one->getNeighborhood()->getSize();i++) {
    one->getNeighborhood()->get(i)->render(SOLID);
  }
}

void PeriTestView::doPhysicsStep(float dt) {
  // to be implemented
}
