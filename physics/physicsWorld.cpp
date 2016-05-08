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
    // to be implemented
  } else {
    // to be implemented
  }
}

void PhysicsWorld::addPhysicsBodyToWorld(PhysicsBodyd* body) {
  if(usingSeparateLists) {
    // to be implemented
  } else {
    // to be implemented
  }
}

void PhysicsWorld::addPhysicsObjectToWorld(PhysicsObjectf* object) {
  if(usingSeparateLists) {
    // to be implemented
  } else {
    // to be implemented
  }
}

void PhysicsWorld::addPhysicsObjectToWorld(PhysicsObjectd* object) {
  if(usingSeparateLists) {
    // to be implemented
  } else {
    // to be implemented
  }
}

void PhysicsWorld::addPeriSystemToWorld(PeriSystemf* peri) {
  if(usingSeparateLists) {
    // to be implemented
  } else {
    // to be implemented
  }
}

void PhysicsWorld::addPeriSystemToWorld(PeriSystemd* peri) {
  if(usingSeparateLists) {
    // to be implemented
  } else {
    // to be implemented
  }
}

Array<PhysicsObjectf*>* PhysicsWorld::getAllObjectsF() { return allObjectsF; }
Array<PhysicsObjectd*>* PhysicsWorld::getAllObjectsD() { return allObjectsD; }
Array<PhysicsBodyf*>* PhysicsWorld::getPhysicsBodiesF() { return physicsBodiesF; }
Array<PhysicsBodyd*>* PhysicsWorld::getPhysicsBodiesD() { return physicsBodiesD; }
Array<PhysicsObjectf*>* PhysicsWorld::getPhysicsObjectsF() { return physicsObjectsF; }
Array<PhysicsObjectd*>* PhysicsWorld::getPhysicsObjectsD() { return physicsObjectsD; }
Array<PeriSystemf*>* PhysicsWorld::getPeriSystemsF() { return periSystemsF; }
Array<PeriSystemd*>* PhysicsWorld::getPeriSystemsD() { return periSystemsD; }
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
void PhysicsWorld::setDoublePercision(bool param) { doublePercision = param; }
void PhysicsWorld::setUsingSeparateLists(bool param) { usingSeparateLists = param; }