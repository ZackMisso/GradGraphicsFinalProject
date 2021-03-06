#include "physicsWorld.h"

PhysicsWorld::PhysicsWorld() {
  doublePercision = false;
  usingSeparateLists = false;
  allObjectsF = new Array<PhysicsObjectf*>();
  allObjectsD = new Array<PhysicsObjectd*>();
  physicsBodiesF = new Array<PhysicsBodyf*>();
  physicsBodiesD = new Array<PhysicsBodyd*>();
  physicsObjectsF = new Array<PhysicsObjectf*>();
  physicsObjectsD = new Array<PhysicsObjectd*>();
  periSystemsF = new Array<PeriSystemf*>();
  periSystemsD = new Array<PeriSystemd*>();
  dummyObjectsF = new Array<DummyObjectf*>();
  dummyObjectsD = new Array<DummyObjectd*>();
  collisionSpringsF = new Array<Springf*>();
  collisionSpringsD = new Array<Springd*>();
}

PhysicsWorld::~PhysicsWorld() {
  // separate cases are used because first implementation
  // will use one single list of all objects.... for
  // simplicity sake.
  if(usingSeparateLists) {
    while(allObjectsF->getSize())
      allObjectsF->removeLast();
    while(allObjectsD->getSize())
      allObjectsD->removeLast();
    while(physicsBodiesF->getSize())
      delete physicsBodiesF->removeLast();
    while(physicsBodiesD->getSize())
      delete physicsBodiesD->removeLast();
    while(physicsObjectsF->getSize())
      delete physicsObjectsF->removeLast();
    while(physicsObjectsD->getSize())
      delete physicsObjectsD->removeLast();
    while(periSystemsF->getSize())
      delete periSystemsF->removeLast();
    while(periSystemsD->getSize())
      delete periSystemsD->removeLast();
  } else {
    while(physicsBodiesF->getSize())
      physicsBodiesF->removeLast();
    while(physicsBodiesD->getSize())
      physicsBodiesD->removeLast();
    while(physicsObjectsF->getSize())
      physicsObjectsF->removeLast();
    while(physicsObjectsD->getSize())
      physicsObjectsD->removeLast();
    while(periSystemsF->getSize())
      periSystemsF->removeLast();
    while(periSystemsD->getSize())
      periSystemsD->removeLast();
    while(allObjectsF->getSize())
      delete allObjectsF->removeLast();
    while(allObjectsD->getSize())
      delete allObjectsD->removeLast();
  }
  while(dummyObjectsF->getSize())
    delete dummyObjectsF->removeLast();
  while(dummyObjectsD->getSize())
    delete dummyObjectsD->removeLast();
  while(collisionSpringsF->getSize())
    delete collisionSpringsF->removeLast();
  while(collisionSpringsD->getSize())
    delete collisionSpringsD->removeLast();
  delete dummyObjectsF;
  delete dummyObjectsD;
  delete collisionSpringsF;
  delete collisionSpringsD;
  delete allObjectsF;
  delete allObjectsD;
  delete physicsBodiesF;
  delete physicsBodiesD;
  delete physicsObjectsF;
  delete physicsObjectsD;
  delete periSystemsF;
  delete periSystemsD;
}

void PhysicsWorld::addPhysicsBodyToWorld(PhysicsBodyf* body) {
  if(usingSeparateLists) {
    physicsBodiesF->add(body);
  } else {
    for(int i=0;i<body->getObjects()->getSize();i++)
      physicsObjectsF->add(body->getObjects()->get(i));
  }
}

void PhysicsWorld::addPhysicsBodyToWorld(PhysicsBodyd* body) {
  if(usingSeparateLists) {
    physicsBodiesD->add(body);
  } else {
    for(int i=0;i<body->getObjects()->getSize();i++)
      physicsObjectsD->add(body->getObjects()->get(i));
  }
}

void PhysicsWorld::addPhysicsObjectToWorld(PhysicsObjectf* object) {
  if(usingSeparateLists) {
    physicsObjectsF->add(object);
  } else {
    physicsObjectsF->add(object);
    // leaving separate just in case future work needs it
  }
}

void PhysicsWorld::addPhysicsObjectToWorld(PhysicsObjectd* object) {
  if(usingSeparateLists) {
    physicsObjectsD->add(object);
  } else {
    physicsObjectsD->add(object);
    // leaving separate just in case future work needs it
  }
}

void PhysicsWorld::addPeriSystemToWorld(PeriSystemf* peri) {
  if(usingSeparateLists) {
    periSystemsF->add(peri);
  } else {
    // leaving separate just in case future work needs it
    periSystemsF->add(peri);
  }
}

void PhysicsWorld::addPeriSystemToWorld(PeriSystemd* peri) {
  if(usingSeparateLists) {
    periSystemsD->add(peri);
  } else {
    // leaving separate just in case future work needs it
    periSystemsD->add(peri);
  }
}

void PhysicsWorld::addDummyObjectToWorld(DummyObjectf* dummy) {
  if(usingSeparateLists) {
    dummyObjectsF->add(dummy);
  } else {
    dummyObjectsF->add(dummy);
  }
}

void PhysicsWorld::addDummyObjectToWorld(DummyObjectd* dummy) {
  if(usingSeparateLists) {
    dummyObjectsD->add(dummy);
  } else {
    dummyObjectsD->add(dummy);
  }
}

void PhysicsWorld::addCollisionSpringToWorld(Springf* spring) {
  if(usingSeparateLists) {
    collisionSpringsF->add(spring);
  } else {
    collisionSpringsF->add(spring);
  }
}

void PhysicsWorld::addCollisionSpringToWorld(Springd* spring) {
  if(usingSeparateLists) {
    collisionSpringsD->add(spring);
  } else {
    collisionSpringsD->add(spring);
  }
}

void PhysicsWorld::clearWorld() {
  if(usingSeparateLists) {
    while(allObjectsF->getSize())
      allObjectsF->removeLast();
    while(allObjectsD->getSize())
      allObjectsD->removeLast();
    while(physicsBodiesF->getSize())
      delete physicsBodiesF->removeLast();
    while(physicsBodiesD->getSize())
      delete physicsBodiesD->removeLast();
    while(physicsObjectsF->getSize())
      delete physicsObjectsF->removeLast();
    while(physicsObjectsD->getSize())
      delete physicsObjectsD->removeLast();
    while(periSystemsF->getSize())
      delete periSystemsF->removeLast();
    while(periSystemsD->getSize())
      delete periSystemsD->removeLast();
  } else {
    while(physicsBodiesF->getSize())
      physicsBodiesF->removeLast();
    while(physicsBodiesD->getSize())
      physicsBodiesD->removeLast();
    while(physicsObjectsF->getSize())
      physicsObjectsF->removeLast();
    while(physicsObjectsD->getSize())
      physicsObjectsD->removeLast();
    while(periSystemsF->getSize())
      periSystemsF->removeLast();
    while(periSystemsD->getSize())
      periSystemsD->removeLast();
    while(allObjectsF->getSize())
      delete allObjectsF->removeLast();
    while(allObjectsD->getSize())
      delete allObjectsD->removeLast();
  }
  while(dummyObjectsF->getSize())
    delete dummyObjectsF->removeLast();
  while(dummyObjectsD->getSize())
    delete dummyObjectsD->removeLast();
  while(collisionSpringsF->getSize())
    delete collisionSpringsF->removeLast();
  while(collisionSpringsD->getSize())
    delete collisionSpringsD->removeLast();
}

Array<PhysicsObjectf*>* PhysicsWorld::getAllObjectsF() { return allObjectsF; }
Array<PhysicsObjectd*>* PhysicsWorld::getAllObjectsD() { return allObjectsD; }
Array<PhysicsBodyf*>* PhysicsWorld::getPhysicsBodiesF() { return physicsBodiesF; }
Array<PhysicsBodyd*>* PhysicsWorld::getPhysicsBodiesD() { return physicsBodiesD; }
Array<PhysicsObjectf*>* PhysicsWorld::getPhysicsObjectsF() { return physicsObjectsF; }
Array<PhysicsObjectd*>* PhysicsWorld::getPhysicsObjectsD() { return physicsObjectsD; }
Array<PeriSystemf*>* PhysicsWorld::getPeriSystemsF() { return periSystemsF; }
Array<PeriSystemd*>* PhysicsWorld::getPeriSystemsD() { return periSystemsD; }
Array<DummyObjectf*>* PhysicsWorld::getDummyObjectsF() { return dummyObjectsF; }
Array<DummyObjectd*>* PhysicsWorld::getDummyObjectsD() { return dummyObjectsD; }
Array<Springf*>* PhysicsWorld::getCollisionSpringsF() { return collisionSpringsF; }
Array<Springd*>* PhysicsWorld::getCollisionSpringsD() { return collisionSpringsD; }
bool PhysicsWorld::getDoublePercision() { return doublePercision; }
bool PhysicsWorld::getUsingSeparateLists() { return usingSeparateLists; }

void PhysicsWorld::setAllObjectsF(Array<PhysicsObjectf*>* param) { allObjectsF = param; }
void PhysicsWorld::setAllObjectsD(Array<PhysicsObjectd*>* param) { allObjectsD = param; }
void PhysicsWorld::setPhysicsBodiesF(Array<PhysicsBodyf*>* param) { physicsBodiesF = param; }
void PhysicsWorld::setPhysicsBodiesD(Array<PhysicsBodyd*>* param) { physicsBodiesD = param; }
void PhysicsWorld::setPhysicsObjectsF(Array<PhysicsObjectf*>* param) { physicsObjectsF = param; }
void PhysicsWorld::setPhysicsObjectsD(Array<PhysicsObjectd*>* param) { physicsObjectsD = param; }
void PhysicsWorld::setPeriSystemsF(Array<PeriSystemf*>* param) { periSystemsF = param; }
void PhysicsWorld::setPeriSystensD(Array<PeriSystemd*>* param) { periSystemsD = param; }
void PhysicsWorld::setDummyObjectsF(Array<DummyObjectf*>* param) { dummyObjectsF = param; }
void PhysicsWorld::setDummyObjectsD(Array<DummyObjectd*>* param) { dummyObjectsD = param; }
void PhysicsWorld::setCollisionSpringsF(Array<Springf*>* param) { collisionSpringsF = param; }
void PhysicsWorld::setCollisionSpringsD(Array<Springd*>* param) { collisionSpringsD = param; }
void PhysicsWorld::setDoublePercision(bool param) { doublePercision = param; }
void PhysicsWorld::setUsingSeparateLists(bool param) { usingSeparateLists = param; }
