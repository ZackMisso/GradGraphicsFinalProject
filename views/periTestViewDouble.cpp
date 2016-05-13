#include "periTestViewDouble.h"
#include "../geometry/bbox.h"
#include "../geometry/voxelizer.h"
#include "../geometry/rectPrism.h"
#include "../physics/collisionMethods.h"
//#include "../peri/pointMass.h"
#include <iostream>

using namespace std;

void PeriTestViewDouble::initialize() {
  cout << "Initializing" << endl;
  collisionObjects = new Array<DummyObjectd*>();
  collisionSprings = new Array<Springd*>();
  BBoxd box = BBoxd(Vec3d(-0.5,-0.3,-0.05),Vec3d(1.0,1.0,0.2));
  cout << "Voxelizing Box" << endl;
  Array<Voxeld*>* voxelMesh = Voxelizer::getInstance()->voxelizeBBox(box,0.05);
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
  periSystem->setSpringDamp(5.0);
  //periSystem->setSpringConstant(60.0);
  //periSystem->setSpringDamp(5.0);
  //periSystem->setSpringConstant(1.0);
  //periSystem->setSpringDamp(0.1);
  cnt = 0;
  periSystem->setSpringBreak(10.0);
  cout << "Converting Voxels To Point Masses" << endl;
  periSystem->convertVoxelsToPoints(voxelMesh);
  cout << "Finished Conversion" << endl;
  for(int i=0;i<periSystem->getPointMasses()->getSize();i++) {
    //periSystem->getPointMasses()->get(i)->getExternelForces()->add(new Vec3d(0.0,-5.0,0.0));
    periSystem->getPointMasses()->get(i)->getExternelForces()->add(new Vec3d(0.0,-4.0,0.0));
    //periSystem->getPointMasses()->get(i)->getExternelForces()->add(new Vec3f(0.0f,-1.0f,0.0f));
  }
  cout << "Creating Collide Object" << endl;
  collideObject = new PhysicsObjectd();
  Vec3d collidePosition = Vec3d(-0.3,-0.9,0.0);
  Vec3d collideDimension = Vec3d(0.6,0.4,0.0);
  collideObject->setGeometry(new RectPrismd(collidePosition,collideDimension));
  collideObject->setPosition(collidePosition);
  cout << "Spring Size: " << periSystem->getSprings()->getSize() << endl;
  cout << "First Ones Springs: " << periSystem->getPointMasses()->get(0)->getNeighborhood()->getSize() << endl;
  cout << "Initializing Finished" << endl;
}

void PeriTestViewDouble::deInitialize() {
  delete periSystem;
  delete collideObject;
  while(collisionSprings->getSize())
    delete collisionSprings->removeLast();
  while(collisionObjects->getSize())
    delete collisionObjects->removeLast();
  delete collisionSprings;
  delete collisionObjects;
}

void PeriTestViewDouble::keyboard(int key,int scancode,int action,int mods) {
  if(key == GLFW_KEY_B && action == GLFW_PRESS) {
    PointMassd* one = periSystem->getPointMasses()->get(0);
    one->setPosition(Vec3d(-0.8,-0.05,0.0));
  }
}

void PeriTestViewDouble::mouseClick(int button,int action,int mods) {
  // to be implemented
}

void PeriTestViewDouble::display() {
  //cout << "Displaying" << endl;
  //cout << "Frame: " << (cnt++) / 10 << endl;
  //cout << "Frame: " << (cnt++) << endl;
  doPhysicsStep(1.0/60.0);
  //cout << "Finished Physics" << endl;
  //doPhysicsStep(1.0f/600.0f);
  //cout << "Exit Physics Step" << endl;

  glClearColor(0.0f,0.0f,0.0f,1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  //cout << "Rendering Peri" << endl;
  glColor3f(1.0f,0.0f,0.0f);
  periSystem->render(WIREFRAME,true);
  glColor3f(0.0f,0.0f,0.0f);
  //cout << "Rendering Box" << endl;
  collideObject->render(WIREFRAME);
  //cout << "Display Done" << endl;
  //glColor3f(0.0f,1.0f,0.0f);
  //PointMassf* one = periSystem->getPointMasses()->get(0);
  //for(int i=0;i<one->getNeighborhood()->getSize();i++) {
  //  one->getNeighborhood()->get(i)->render(SOLID);
  //}
}

void PeriTestViewDouble::doPhysicsStep(double dt) {
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
      PhysicsObjectd* two = (PhysicsObjectd*)collisionSprings->get(i)->getTwoRef();
      //cout << "Hey Listen" << endl;
      DummyObjectd* one = (DummyObjectd*)collisionSprings->get(i)->getOneRef();
      //cout << "Hey Listen" << endl;
      two->getCollisionForces()->remove(collisionSprings->get(i));
      //cout << "Hey Listen" << endl;
      collisionObjects->remove(one);
      //cout << "Hey Listen" << endl;
      Springd* spring = collisionSprings->get(i);
      //cout << "Hey Listen" << endl;
      collisionSprings->removeEff(i);
      //cout << "Hey Listen" << endl;
      i--;
      cout << "Before Delete" << endl;
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
  Array<PointMassd*>* pointMasses = periSystem->getPointMasses();
  //for(int i=0;i<collision)
  for(int i=0;i<pointMasses->getSize();i++) {
    BBoxd one = pointMasses->get(i)->getGeometry()->getBBox();
    BBoxd two = collideObject->getGeometry()->getBBox();
    double tmp;
    Vec3d tmp2;
    if(CollisionMethods::getInstance()->bboxOnbbox(one,two,&tmp,&tmp2)) {
      bool exists = false;
      Array<Springd*>* sprs = pointMasses->get(i)->getCollisionForces();
      for(int j=0;j<sprs->getSize();j++) {
        if(sprs->get(j)->isEqual(0x0,(void*)pointMasses->get(i)))
          exists = true;
      }
      //cout << "Collision Found: " << cnt << endl;
      if(!exists) {
        DummyObjectd* obj = new DummyObjectd(collideObject,periSystem->getPointMasses()->get(i));
        collisionObjects->add(obj);
        Springd* spring = new Springd((void*)obj,(void*)pointMasses->get(i));
        spring->setSpringConstant(500.0);
        spring->setDampConstant(8.0);
        spring->setIsCollisionSpring(true);
        pointMasses->get(i)->getCollisionForces()->add(spring);
        collisionSprings->add(spring);
        cnt++;
        //cout << "There was a Collision" << endl;
      }// else {
      //  cout << "IT EXISTS" << endl;
      //}
    }
  }
  //cout << "Finished Collision Resolution" << endl;

}
