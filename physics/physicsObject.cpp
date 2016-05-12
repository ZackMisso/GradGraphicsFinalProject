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
  eulerIntegration(dt);
}

void PhysicsObjectf::eulerIntegration(float dt) {
  Vec3f force = Vec3f();
  if(!noForce) {
    force = accumulateForces(dt);
  }
  Vec3f acc = Vec3f(force[0]/mass,force[1]/mass,force[2]/mass);
  position[0] = position[0] + velocity[0] * dt;
  position[1] = position[1] + velocity[1] * dt;
  position[2] = position[2] + velocity[2] * dt;
  velocity[0] = velocity[0] + acc[0] * dt;
  velocity[1] = velocity[1] + acc[1] * dt;
  velocity[2] = velocity[2] + acc[2] * dt;
}

void PhysicsObjectf::implicitIntegration(float dt) {
  // to be implemented
}

Vec3f PhysicsObjectf::accumulateForces(float dt) {
  Vec3f totalForce = Vec3f();
  for(int i=0;i<externalForces->getSize();i++) {
    totalForce = totalForce + *(externalForces->get(i));
  }
  for(int i=0;i<collisionForces->getSize();i++) {
    Vec3f force = collisionForces->get(i)->getForceForObject((void*)this);
    // spring dampening
    float dampC = collisionForces->get(i)->getDampConstant();
    force = force - Vec3f(dampC*velocity[0],dampC*velocity[1],dampC*velocity[2]);
    // acumulate dampened force
    totalForce = totalForce + force;
  }
  //cout << "Total Force: ";
  //totalForce.debug();
  return totalForce;
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

void PhysicsObjectd::eulerIntegration(double dt) {
  // to be implemented
}

void PhysicsObjectd::implicitIntegration(double dt) {
  // to be implemented
}

Vec3d PhysicsObjectd::accumulateForces(double dt) {
  // to be implemented
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
