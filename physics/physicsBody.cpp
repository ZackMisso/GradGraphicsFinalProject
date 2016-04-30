#include "physicsBody.h"

PhysicsBodyf::PhysicsBodyf() {
  objects = new Array<PhysicsObjectf*>();
  bbox = BBoxf();
  proximity = 0.0f;
}

PhysicsBodyf::~PhysicsBodyf() {
  while(objects->getSize())
    objects->removeLast();
  delete objects;
}

void PhysicsBodyf::calculateBBox() {
  // to be implemented
}

Array<PhysicsObjectf*>* PhysicsBodyf::getObjects() { return objects; }
BBoxf PhysicsBodyf::getBBox() { return bbox; }
float PhysicsBodyf::getProximity() { return proximity; }

void PhysicsBodyf::setObjects(Array<PhysicsObjectf*>* param) { objects = param; }
void PhysicsBodyf::setBBox(BBoxf param) { bbox = param; }
void PhysicsBodyf::setProximity(float param) { proximity = param; }

///////////////////////// DOUBLE VERSION //////////////////////////

PhysicsBodyd::PhysicsBodyd() {
  objects = new Array<PhysicsObjectd*>();
  bbox = BBoxd();
  proximity = 0.0;
}

PhysicsBodyd::~PhysicsBodyd() {
  while(objects->getSize())
    objects->removeLast();
  delete objects;
}

void PhysicsBodyd::calculateBBox() {
  // to be implemented
}

Array<PhysicsObjectd*>* PhysicsBodyd::getObjects() { return objects; }
BBoxd PhysicsBodyd::getBBox() { return bbox; }
double PhysicsBodyd::getProximity() { return proximity; }

void PhysicsBodyd::setObjects(Array<PhysicsObjectd*>* param) { objects = param; }
void PhysicsBodyd::setBBox(BBoxd param) { bbox = param; }
void PhysicsBodyd::setProximity(double param) { proximity = param; }
