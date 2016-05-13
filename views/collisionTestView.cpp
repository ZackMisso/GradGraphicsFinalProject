#include "collisionTestView.h"
#include "../io/frameWriter.h"
#include "../io/simulationStateWriter.h"
#include "../physics/collisionMethods.h"
#include "../physics/dummyObject.h"
#include <iostream>

using namespace std;

void CollisionTestView::initialize() {
  one = new PhysicsObjectf();
  two = new PhysicsObjectf();
  Vec3f onePosition = Vec3f(-0.1f,0.1f,0.0f);
  Vec3f twoPosition = Vec3f(-0.5f,-0.7,0.0f);
  Vec3f oneDimension = Vec3f(0.2f,0.2f,0.0f);
  Vec3f twoDimension = Vec3f(1.0f,0.4f,0.0f);
  onePr = new RectPrismf(onePosition,oneDimension);
  twoPr = new RectPrismf(twoPosition,twoDimension);
  one->setGeometry(onePr);
  two->setGeometry(twoPr);
  one->setPosition(onePosition);
  two->setPosition(twoPosition);
  Vec3f* grav = new Vec3f(0.0f,-0.05f,0.0f);
  one->getExternelForces()->add(grav);
  //one->setVelocity(Vec3f(0.0f,-0.05f,0.0f));
  collisionSpring = 0x0;
  isWireFrame = false;
  cnt = 0;
}

void CollisionTestView::deInitialize() {
  delete one;
  delete two;
  if(collisionSpring)
    delete collisionSpring;
}

void CollisionTestView::keyboard(int key,int scancode,int action,int mods) {
  if(key == GLFW_KEY_W && action == GLFW_PRESS) {
    isWireFrame = !isWireFrame;
  }
}

void CollisionTestView::mouseClick(int button,int action,int mods) {
  // to be implemented
}

void CollisionTestView::display() {
  //cout << "Began Step" << endl;
  doPhysicsStep(1.0f/60.0f);
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

void CollisionTestView::doPhysicsStep(float dt) {
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
  float tmp;
  Vec3f tmp2;
  if(CollisionMethods::getInstance()->bboxOnbbox(one->getGeometry()->getBBox(),two->getGeometry()->getBBox(),&tmp,&tmp2)) {
    //cout << "There Was A Collision" << endl;
    if(!collisionSpring) {
      collisionSpring = new Springf((void*)(new DummyObjectf(two,one)),(void*)one);
      collisionSpring->setDampConstant(5.0f);
      collisionSpring->setSpringConstant(60.0f);
      collisionSpring->setIsCollisionSpring(true);
      one->getCollisionForces()->add(collisionSpring);
      //two->getCollisionForces()->add(collisionSpring);
    }
  }
}

void CollisionTestView::headless() {
  int numFrames = 300;
  for(int i=0;i<numFrames;i++) {
    doPhysicsStep(1.0f/60.0f);
    // implement file writes
    char buff[32];
    sprintf(buff, "frames/frame%05d.vox", i);
    ofstream file(buff);
    FrameWriter::getInstance()->writePhysicsObject(one, file);
    FrameWriter::getInstance()->writePhysicsObject(two, file);
    file.close();
  }
}
