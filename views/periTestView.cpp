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
  collisionSprings = new Array<Springf*>();
  BBoxf box = BBoxf(Vec3f(-0.5f,-0.3f,-0.05f),Vec3f(1.0f,1.0f,0.1f));
  Array<Voxelf*>* voxelMesh = Voxelizer::getInstance()->voxelizeBBox(box,0.05f);
  //Array<Voxelf*>* voxelMesh = Voxelizer::getInstance()->voxelizeBBox(box,0.5f);
  cout << "Voxel Mesh Size: " << voxelMesh->getSize() << endl;
  periSystem = new PeriSystemf();
  periSystem->setPointMassR(0.05f);
  periSystem->setPointMassM(1.0f);
  periSystem->setPointMassH(0.31f);
  //periSystem->setPointMassH(0.31f);
  periSystem->setSpringConstant(10.0f);
  periSystem->setSpringDamp(5.0f);
  //periSystem->setSpringConstant(60.0f);
  //periSystem->setSpringDamp(5.0f);
  //periSystem->setSpringConstant(1.0f);
  //periSystem->setSpringDamp(0.1f);
  cnt = 0;
  periSystem->setSpringBreak(10.0f);
  periSystem->convertVoxelsToPoints(voxelMesh);
  for(int i=0;i<periSystem->getPointMasses()->getSize();i++) {
    periSystem->getPointMasses()->get(i)->getExternelForces()->add(new Vec3f(0.0f,-1.0f,0.0f));
    //periSystem->getPointMasses()->get(i)->getExternelForces()->add(new Vec3f(0.0f,-1.0f,0.0f));
  }
  collideObject = new PhysicsObjectf();
  Vec3f collidePosition = Vec3f(-0.3f,-0.9,0.0f);
  Vec3f collideDimension = Vec3f(0.6f,0.4f,0.0f);
  collideObject->setGeometry(new RectPrismf(collidePosition,collideDimension));
  collideObject->setPosition(collidePosition);
  cout << "Spring Size: " << periSystem->getSprings()->getSize() << endl;
  cout << "First Ones Springs: " << periSystem->getPointMasses()->get(0)->getNeighborhood()->getSize() << endl;
}

void PeriTestView::deInitialize() {
  delete periSystem;
  delete collideObject;
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
    one->setPosition(Vec3f(-0.8f,-0.05f,0.0f));
  }
}

void PeriTestView::mouseClick(int button,int action,int mods) {
  // to be implemented
}

void PeriTestView::display() {
  //cout << "Frame: " << (cnt++) / 10 << endl;
  //cout << "Frame: " << (cnt++) << endl;
  doPhysicsStep(1.0f/60.0f);
  //doPhysicsStep(1.0f/600.0f);
  //cout << "Exit Physics Step" << endl;

  glClearColor(0.0f,0.0f,0.0f,1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  periSystem->render(WIREFRAME,true);
  glColor3f(1.0f,0.0f,0.0f);
  collideObject->render(WIREFRAME);

  //glColor3f(0.0f,1.0f,0.0f);
  //PointMassf* one = periSystem->getPointMasses()->get(0);
  //for(int i=0;i<one->getNeighborhood()->getSize();i++) {
  //  one->getNeighborhood()->get(i)->render(SOLID);
  //}
}

void PeriTestView::doPhysicsStep(float dt) {
  //cout << "PHYSICSC" << endl;
  //cout << "Start Physics Step" << endl;
  for(int i=0;i<collisionSprings->getSize();i++) {
    //cout << "WHAT" << endl;
    //if(collisionSprings->get(i)==0x0) {
      //cout << "WHAT THE FUCK" << endl;
    //}
    //cout << "Setting Current Positions" << endl;
    collisionSprings->get(i)->setCurrentPositions();
    //cout << "Updateing RestPosition" << endl;
    collisionSprings->get(i)->calculateCurrentRestPosition();
    //cout << "Calculating Force" << endl;
    collisionSprings->get(i)->calculateForce();
    //cout << "Calculating Potential" << endl;
    collisionSprings->get(i)->calculatePotential();
    //cout << "HI" << endl;
    if(collisionSprings->get(i)->shouldDestroySpring()) {
      //cout << "Hey Listen" << endl;
      PhysicsObjectf* two = (PhysicsObjectf*)collisionSprings->get(i)->getTwoRef();
      //cout << "Hey Listen" << endl;
      DummyObjectf* one = (DummyObjectf*)collisionSprings->get(i)->getOneRef();
      //cout << "Hey Listen" << endl;
      two->getCollisionForces()->remove(collisionSprings->get(i));
      //cout << "Hey Listen" << endl;
      collisionObjects->remove(one);
      //cout << "Hey Listen" << endl;
      Springf* spring = collisionSprings->get(i);
      //cout << "Hey Listen" << endl;
      collisionSprings->removeEff(i);
      //cout << "Hey Listen" << endl;
      i--;
      //cout << "Before Delete" << endl;
      delete spring;
      delete one;
      cnt--;
      //cout << "After Delete" << endl;
      spring = 0x0;
      //cout << "WHY" << endl;
    }
  }
  //cout << "Finish Collision Springs Update" << endl;

  periSystem->performPhysicsStep(dt);
  //cout << "Finish Peri System Update" << endl;
  Array<PointMassf*>* pointMasses = periSystem->getPointMasses();
  //for(int i=0;i<collision)
  for(int i=0;i<pointMasses->getSize();i++) {
    BBoxf one = pointMasses->get(i)->getGeometry()->getBBox();
    BBoxf two = collideObject->getGeometry()->getBBox();
    float tmp;
    Vec3f tmp2;
    if(CollisionMethods::getInstance()->bboxOnbbox(one,two,&tmp,&tmp2)) {
      bool exists = false;
      Array<Springf*>* sprs = pointMasses->get(i)->getCollisionForces();
      for(int j=0;j<sprs->getSize();j++) {
        if(sprs->get(j)->isEqual(0x0,(void*)pointMasses->get(i)))
          exists = true;
      }
      cout << "Collision Found: " << cnt << endl;
      if(!exists) {
        DummyObjectf* obj = new DummyObjectf(collideObject,periSystem->getPointMasses()->get(i));
        collisionObjects->add(obj);
        Springf* spring = new Springf((void*)obj,(void*)pointMasses->get(i));
        spring->setSpringConstant(60.0f);
        spring->setDampConstant(5.0f);
        spring->setIsCollisionSpring(true);
        pointMasses->get(i)->getCollisionForces()->add(spring);
        collisionSprings->add(spring);
        cnt++;
        cout << "There was a Collision" << endl;
      }// else {
      //  cout << "IT EXISTS" << endl;
      //}
    }
  }
  //cout << "Finished Collision Resolution" << endl;

}
