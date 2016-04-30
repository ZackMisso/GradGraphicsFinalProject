#include "physicsObject.h"

PhysicsObjectf::PhysicsObjectf() {
  externalForces = new Array<Vec3f*>();
  position = Vec3f();
  velocity = Vec3f();
  mass = 1.0f;
}

PhysicsObjectf::~PhysicsObjectf() {
  while(externalForces->getSize())
    delete externalForces->removeLast();
  delete externalForces;
}

void PhysicsObjectf::performPhysicsStep(float dt) {
  // to be extended
}

Array<Vec3f*>* PhysicsObjectf::getExternelForces() { return externalForces; }
Vec3f PhysicsObjectf::getPosition() { return position; }
Vec3f PhysicsObjectf::getVelocity() { return velocity; }
float PhysicsObjectf::getMass() { return mass; }

void PhysicsObjectf::setExternelForces(Array<Vec3f*>* param) { externalForces = param; }
void PhysicsObjectf::setPosition(Vec3f param) { position = param; }
void PhysicsObjectf::setVelocity(Vec3f param) { velocity = param; }
void PhysicsObjectf::setMass(float param) { mass = param; }

////////////////////////// DOUBLE VERSION ///////////////////////////

PhysicsObjectd::PhysicsObjectd() {
  externalForces = new Array<Vec3d*>();
  position = Vec3d();
  velocity = Vec3d();
  mass = 1.0;
}

PhysicsObjectd::~PhysicsObjectd() {
  while(externalForces->getSize())
    delete externalForces->removeLast();
  delete externalForces;
}

void PhysicsObjectd::performPhysicsStep(double dt) {
  // to be extended
}

Array<Vec3d*>* PhysicsObjectd::getExternelForces() { return externalForces; }
Vec3d PhysicsObjectd::getPosition() { return position; }
Vec3d PhysicsObjectd::getVelocity() { return velocity; }
double PhysicsObjectd::getMass() { return mass; }

void PhysicsObjectd::setExternelForces(Array<Vec3d*>* param) { externalForces = param; }
void PhysicsObjectd::setPosition(Vec3d param) { position = param; }
void PhysicsObjectd::setVelocity(Vec3d param) { velocity = param; }
void PhysicsObjectd::setMass(double param) { mass = param; }
