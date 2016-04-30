#include "pointMass.h"
#include "periConstants.h"

PointMassf::PointMassf() {
  neighborhood = new Array<Springf*>();
  id = PeriConstants::getNextID();
  // to be implemented
}

PointMassf::~PointMassf() {
  while(neighborhood->getSize())
    delete neighborhood->removeLast();
  delete neighborhood;
}

void PointMassf::performPhysicsStep(float dt) {
  // to be implemented
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
Vec3f PointMassf::getOriginalPosition() { return originalPosition; }
float PointMassf::getRadius() { return radius; }
float PointMassf::getVolume() { return volume; }

void PointMassf::setNeighborhood(Array<Springf*>* param) { neighborhood = param; }
void PointMassf::setOriginalPosition(Vec3f param) { originalPosition = param; }
void PointMassf::setRadius(float param) { radius = param; }

/////////////////////////// DOUBLE VERSION //////////////////////////////

PointMassd::PointMassd() {
  neighborhood = new Array<Springd*>();
  id = PeriConstants::getNextID();
  // to be implemented
}

PointMassd::~PointMassd() {
  while(neighborhood->getSize())
    delete neighborhood->removeLast();
  delete neighborhood;
}

void PointMassd::performPhysicsStep(double dt) {
  // to be implemented
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
Vec3d PointMassd::getOriginalPosition() { return originalPosition; }
double PointMassd::getRadius() { return radius; }
double PointMassd::getVolume() { return volume; }

void PointMassd::setNeighborhood(Array<Springd*>* param) { neighborhood = param; }
void PointMassd::setOriginalPosition(Vec3d param) { originalPosition = param; }
void PointMassd::setRadius(double param) { radius = param; }
