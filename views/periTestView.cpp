#include "periTestView.h"
#include "../geometry/bbox.h"
#include "../geometry/voxelizer.h"
#include "../geometry/rectPrism.h"
#include "../physics/collisionMethods.h"
//#include "../peri/pointMass.h"
#include <iostream>

using namespace std;

void PeriTestView::initialize() {
  collisionObjects = new Array<DummyObjectf*>();
  BBoxf box = BBoxf(Vec3f(-0.5f,-0.3f,-0.05f),Vec3f(1.0f,1.0f,0.1f));
  Array<Voxelf*>* voxelMesh = Voxelizer::getInstance()->voxelizeBBox(box,0.05f);
  cout << "Voxel Mesh Size: " << voxelMesh->getSize() << endl;
  periSystem = new PeriSystemf();
  periSystem->setPointMassR(0.05f);
  periSystem->setPointMassM(1.0f);
  periSystem->setPointMassH(0.21f);
  periSystem->setSpringConstant(10.0f);
  periSystem->setSpringDamp(5.0f);
  //periSystem->setSpringConstant(1.0f);
  //periSystem->setSpringDamp(0.1f);
  periSystem->setSpringBreak(10.0f);
  periSystem->convertVoxelsToPoints(voxelMesh);
  //for(int i=0;i<periSystem->getPointMasses()->getSize();i++) {
  //  periSystem->getPointMasses()->get(i)->getExternelForces()->add(new Vec3f(0.0f,-1.0f,0.0f));
  //}
  collideObject = new PhysicsObjectf();
  Vec3f collidePosition = Vec3f(-0.8f,-0.9,0.0f);
  Vec3f collideDimension = Vec3f(1.6f,0.4f,0.0f);
  collideObject->setGeometry(new RectPrismf(collidePosition,collideDimension));
  collideObject->setPosition(collidePosition);
  cout << "Spring Size: " << periSystem->getSprings()->getSize() << endl;
  cout << "First Ones Springs: " << periSystem->getPointMasses()->get(0)->getNeighborhood()->getSize() << endl;
}

void PeriTestView::deInitialize() {
  delete periSystem;
  delete collisionObject;
  while(collisionSprings->getSize())
    delete collisionSprings->removeLast();
  while(collisionObjects->getSize())
    delete collisionObjects->removeLast();
  delete collisionSprings;
  delete collisionObjects;
}

void PeriTestView::keyboard(int key,int scancode,int action,int mods) {
  if(key == GLFW_KEY_B && action == GLFW_PRESS) {
    PointMassf* one = periSystem->getPointMasses()->get(0);
    one->setPosition(Vec3f(-0.8f,-0.8f,0.0f));
  }
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
  glColor3f(1.0f,0.0f,0.0f);
  collideObject->render(WIREFRAME);

  glColor3f(0.0f,1.0f,0.0f);
  PointMassf* one = periSystem->getPointMasses()->get(0);
  for(int i=0;i<one->getNeighborhood()->getSize();i++) {
    one->getNeighborhood()->get(i)->render(SOLID);
  }
}

void PeriTestView::doPhysicsStep(float dt) {
  //cout << "PHYSICSC" << endl;
  for(int i=0;i<collisionSprings->getSize();i++) {
    collisionSprings->get(i)->setCurrentPositions();
    collisionSprings->get(i)->calculateCurrentRestPosition();
    collisionSprings->get(i)->calculateForce();
    collisionSprings->get(i)->calculatePotential();
    if(collisionSprings->get(i)->shouldDestroySpring()) {
      PhysicsObjectf* two = (PhysicsObjectf*)collisionSprings->getTwoRef();
      DummyObjectf* one = (DummyObjectf*)collisionSprings->getOneRef();
      one->getCollisionForces()->remove(collisionSprings->get(i));
      collisionObjects->remove(one);
      Springf* spring = collisionSprings->get(i);
      collisionObjects->removeEff(i);
      i--;
      delete spring;
    }
  }

  periSystem->performPhysicsStep(dt);
  Array<PointMassf*>* pointMasses = periSystem->getPointMasses();
  //for(int i=0;i<collision)
  for(int i=0;i<pointMasses->getSize();i++) {
    BBoxf one = pointMasses->get(i)->getGeometry()->getBBox();
    BBoxf two = collideObject->getGeometry()->getBBox();
    float tmp;
    Vec3f tmp2;
    if(CollisionMethods::getInstance()->bboxOnbbox(one,two,&tmp,&tmp2)) {
      DummyObjectf* obj = new DummyObjectf(collideObject,pointMasses()->get(i));
      collisionObjects->add(obj);
      Springf* spring = new Springf((void*)obj,(void*)pointMasses->get(i));
      spring->setSpringConstant(10.0f);
      spring->setSpringDamp(5.0f);
      spring->setIsCollisionSpring(true);
      pointMasses->get(i)->getCollisionForces()->add(spring);
    }
  }

}
