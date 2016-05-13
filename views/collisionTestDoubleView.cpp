#include "collisionTestDoubleView.h"
#include "../io/frameWriter.h"
#include "../io/simulationStateWriter.h"
#include "../physics/collisionMethods.h"
#include "../physics/dummyObject.h"
#include <iostream>

using namespace std;

void CollisionTestDoubleView::initialize() {
  one = new PhysicsObjectd();
  two = new PhysicsObjectd();
  Vec3d onePosition = Vec3d(-0.1,0.1,0.0);
  Vec3d twoPosition = Vec3d(-0.5,-0.7,0.0);
  Vec3d oneDimension = Vec3d(0.2,0.2,0.0);
  Vec3d twoDimension = Vec3d(1.0,0.4,0.0);
  onePr = new RectPrismd(onePosition,oneDimension);
  twoPr = new RectPrismd(twoPosition,twoDimension);
  one->setGeometry(onePr);
  two->setGeometry(twoPr);
  one->setPosition(onePosition);
  two->setPosition(twoPosition);
  Vec3d* grav = new Vec3d(0.0,-0.05,0.0);
  one->getExternelForces()->add(grav);
  //one->setVelocity(Vec3f(0.0f,-0.05f,0.0f));
  collisionSpring = 0x0;
  isWireFrame = false;
  cnt = 0;
}

void CollisionTestDoubleView::deInitialize() {
  delete one;
  delete two;
  if(collisionSpring)
    delete collisionSpring;
}

void CollisionTestDoubleView::keyboard(int key,int scancode,int action,int mods) {
  if(key == GLFW_KEY_W && action == GLFW_PRESS) {
    isWireFrame = !isWireFrame;
  }
}

void CollisionTestDoubleView::mouseClick(int button,int action,int mods) {
  // to be implemented
}

void CollisionTestDoubleView::display() {
  //cout << "Began Step" << endl;
  doPhysicsStep(1.0/60.0);
  //cout << "Finished Step" << endl;
  //cout << cnt++ << endl;

  glClearColor(0.0f,0.0f,0.0f,1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glColor3f(1.0,0.0,0.0);

  if(!isWireFrame) {
    onePr->render(SOLID);
    twoPr->render(SOLID);
  } else {
    onePr->render(WIREFRAME);
    twoPr->render(WIREFRAME);
  }
  //cout << "Drew Stuff" << endl;

  glColor3f(0.0f,0.0f,1.0f);
  //cout << "Drawing Spring" << endl;
  if(collisionSpring)
    collisionSpring->render(SOLID);
  //cout << "DUH" << endl;
}

void CollisionTestDoubleView::doPhysicsStep(double dt) {
  if(collisionSpring) {
    collisionSpring->setCurrentPositions();
    collisionSpring->calculateCurrentRestPosition();
    collisionSpring->calculateForce();
    collisionSpring->calculatePotential();
    if(collisionSpring->shouldDestroySpring()) {
      //cout << "Destroying Spring" << endl;
      one->getCollisionForces()->remove(collisionSpring);
      delete collisionSpring;
      //cout << "Spring Destroyed" << endl;
      collisionSpring = 0x0;
    }
  }
  //cout << "Performing One Update" << endl;
  one->performPhysicsStep(dt);
  //cout << "Finished One Update" << endl;
  double tmp;
  Vec3d tmp2;
  if(CollisionMethods::getInstance()->bboxOnbbox(one->getGeometry()->getBBox(),two->getGeometry()->getBBox(),&tmp,&tmp2)) {
    //cout << "There Was A Collision" << endl;
    if(!collisionSpring) {
      collisionSpring = new Springd((void*)(new DummyObjectd(two,one)),(void*)one);
      collisionSpring->setDampConstant(2.0);
      collisionSpring->setSpringConstant(60.0);
      collisionSpring->setIsCollisionSpring(true);
      one->getCollisionForces()->add(collisionSpring);
      //two->getCollisionForces()->add(collisionSpring);
    }
  }
}

void CollisionTestDoubleView::headless() {
  int numFrames = 300;
  for(int i=0;i<numFrames;i++) {
    doPhysicsStep(1.0/60.0);
    // implement file writes
    char buff[32];
    sprintf(buff, "frames/frame%05d.vox", i);
    ofstream file(buff);
    FrameWriter::getInstance()->writePhysicsObject(one, file);
    FrameWriter::getInstance()->writePhysicsObject(two, file);
    file.close();
  }
}
