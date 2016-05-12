#include "physicsObject.h"

PhysicsObjectf::PhysicsObjectf() {
  collisionForces = new Array<Springf*>();
  externalForces = new Array<Vec3f*>();
  geometry = 0x0;
  position = Vec3f();
  velocity = Vec3f();
  mass = 1.0f;
  noForce = false;
}

PhysicsObjectf::~PhysicsObjectf() {
  while(externalForces->getSize())
    delete externalForces->removeLast();
  while(collisionForces->getSize())
    delete collisionForces->removeLast();
  delete externalForces;
  delete collisionForces;
  if(geometry)
    delete geometry;
}

void PhysicsObjectf::performPhysicsStep(float dt) {
  // to be extended
}

Array<Springf*>* PhysicsObjectf::getCollisionForces() { return collisionForces; }
Array<Vec3f*>* PhysicsObjectf::getExternelForces() { return externalForces; }
Geometryf* PhysicsObjectf::getGeometry() { return geometry; }
Vec3f PhysicsObjectf::getPosition() { return position; }
Vec3f PhysicsObjectf::getVelocity() { return velocity; }
float PhysicsObjectf::getMass() { return mass; }
bool PhysicsObjectf::getNoForce() { return noForce; }

void PhysicsObjectf::setCollisionForces(Array<Springf*>* param) { collisionForces = param; }
void PhysicsObjectf::setExternelForces(Array<Vec3f*>* param) { externalForces = param; }
void PhysicsObjectf::setGeometry(Geometryf* param) { geometry = param; }
void PhysicsObjectf::setPosition(Vec3f param) { position = param; }
void PhysicsObjectf::setVelocity(Vec3f param) { velocity = param; }
void PhysicsObjectf::setMass(float param) { mass = param; }
void PhysicsObjectf::setNoForce(bool param) { noForce = param; }

////////////////////////// DOUBLE VERSION ///////////////////////////

PhysicsObjectd::PhysicsObjectd() {
  collisionForces = new Array<Springd*>();
  externalForces = new Array<Vec3d*>();
  geometry = 0x0;
  position = Vec3d();
  velocity = Vec3d();
  mass = 1.0;
  noForce = false;
}

PhysicsObjectd::~PhysicsObjectd() {
  while(externalForces->getSize())
    delete externalForces->removeLast();
  while(collisionForces->getSize())
    delete collisionForces->removeLast();
  delete externalForces;
  delete collisionForces;
  if(geometry)
    delete geometry;
}

void PhysicsObjectd::performPhysicsStep(double dt) {
  // to be extended
}

Array<Springd*>* PhysicsObjectd::getCollisionForces() { return collisionForces; }
Array<Vec3d*>* PhysicsObjectd::getExternelForces() { return externalForces; }
Geometryd* PhysicsObjectd::getGeometry() { return geometry; }
Vec3d PhysicsObjectd::getPosition() { return position; }
Vec3d PhysicsObjectd::getVelocity() { return velocity; }
double PhysicsObjectd::getMass() { return mass; }
bool PhysicsObjectd::getNoForce() { return noForce; }

void PhysicsObjectd::setCollisionForces(Array<Springd*>* param) { collisionForces = param; }
void PhysicsObjectd::setExternelForces(Array<Vec3d*>* param) { externalForces = param; }
void PhysicsObjectd::setGeometry(Geometryd* param) { geometry = param; }
void PhysicsObjectd::setPosition(Vec3d param) { position = param; }
void PhysicsObjectd::setVelocity(Vec3d param) { velocity = param; }
void PhysicsObjectd::setMass(double param) { mass = param; }
void PhysicsObjectd::setNoForce(bool param) { noForce = param; }
