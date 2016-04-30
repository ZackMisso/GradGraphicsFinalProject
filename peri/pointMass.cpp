#include "pointMass.h"
#include "periConstants.h"

PointMassf::PointMassf() {
  neighborhood = new Array<Springf*>();
  externalForces = new Array<Vec3f*>();
  id = PeriConstants::getNextID();
  // to be implemented
}

PointMassf::~PointMassf() {
  while(neighborhood->getSize())
    delete neighborhood->removeLast();
  while(externalForces->getSize())
    delete externalForces->removeLast();
  delete neighborhood;
  delete externalForces;
}

Vec3f PointMassf::accumulateForces() {
  // to be implemented
  return Vec3f();
}

void PointMassf::physicsUpdate() {
  // to be implemented
}

void PointMassf::calculateVolume() {
  // to be implemented
}

Array<Springf*>* PointMassf::getNeighborhood() { return neighborhood; }
Array<Vec3f*>* PointMassf::getExternelForces() { return externalForces; }
Vec3f PointMassf::getOriginalPosition() { return originalPosition; }
Vec3f PointMassf::getPosition() { return position; }
Vec3f PointMassf::getVelocity() { return velocity; }
float PointMassf::getMass() { return mass; }
float PointMassf::getRadius() { return radius; }
float PointMassf::getVolume() { return volume; }

void PointMassf::setNeighborhood(Array<Springf*>* param) { neighborhood = param; }
void PointMassf::setExternelForces(Array<Vec3f*>* param) { externalForces = param; }
void PointMassf::setOriginalPosition(Vec3f param) { originalPosition = param; }
void PointMassf::setPosition(Vec3f param) { position = param; }
void PointMassf::setVelocity(Vec3f param) { velocity = param; }
void PointMassf::setMass(float param) { mass = param; }
void PointMassf::setRadius(float param) { radius = param; }

/////////////////////////// DOUBLE VERSION //////////////////////////////

PointMassd::PointMassd() {
  neighborhood = new Array<Springd*>();
  externalForces = new Array<Vec3d*>();
  id = PeriConstants::getNextID();
  // to be implemented
}

PointMassd::~PointMassd() {
  while(neighborhood->getSize())
    delete neighborhood->removeLast();
  while(externalForces->getSize())
    delete externalForces->removeLast();
  delete neighborhood;
  delete externalForces;
}

Vec3d PointMassd::accumulateForces() {
  // to be implemented
  return Vec3d();
}

void PointMassd::physicsUpdate() {
  // to be implemented
}

void PointMassd::calculateVolume() {
  // to be implemented
}

Array<Springd*>* PointMassd::getNeighborhood() { return neighborhood; }
Array<Vec3d*>* PointMassd::getExternelForces() { return externalForces; }
Vec3d PointMassd::getOriginalPosition() { return originalPosition; }
Vec3d PointMassd::getPosition() { return position; }
Vec3d PointMassd::getVelocity() { return velocity; }
double PointMassd::getMass() { return mass; }
double PointMassd::getRadius() { return radius; }
double PointMassd::getVolume() { return volume; }

void PointMassd::setNeighborhood(Array<Springd*>* param) { neighborhood = param; }
void PointMassd::setExternelForces(Array<Vec3d*>* param) { externalForces = param; }
void PointMassd::setOriginalPosition(Vec3d param) { originalPosition = param; }
void PointMassd::setPosition(Vec3d param) { position = param; }
void PointMassd::setVelocity(Vec3d param) { velocity = param; }
void PointMassd::setMass(double param) { mass = param; }
void PointMassd::setRadius(double param) { radius = param; }
