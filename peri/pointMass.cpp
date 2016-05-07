#include "pointMass.h"
#include "periConstants.h"

PointMassf::PointMassf() {
  neighborhood = new Array<Springf*>();
  id = PeriConstants::getNextID();
  mesh = 0x0;
  // to be implemented
}

PointMassf::~PointMassf() {
  while(neighborhood->getSize())
    delete neighborhood->removeLast();
  delete neighborhood;
  delete mesh;
}

void PointMassf::performPhysicsStep(float dt) {
  // to be implemented
}

float PointMassf::getDistTo(PointMassf* other) {
  Vec3f dist = position - other->position;
  return dist.mag();
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
Voxelf* PointMassf::getMesh() { return mesh; }
Vec3f PointMassf::getOriginalPosition() { return originalPosition; }
float PointMassf::getRadius() { return radius; }
float PointMassf::getVolume() { return volume; }
int PointMassf::getID() { return id; }

void PointMassf::setNeighborhood(Array<Springf*>* param) { neighborhood = param; }
void PointMassf::setMesh(Voxelf* param) { mesh = param; }
void PointMassf::setOriginalPosition(Vec3f param) { originalPosition = param; }
void PointMassf::setRadius(float param) { radius = param; }
void PointMassf::setVolume(float param) { volume = param; }
void PointMassf::setID(int param) { id = param; }

/////////////////////////// DOUBLE VERSION //////////////////////////////

PointMassd::PointMassd() {
  neighborhood = new Array<Springd*>();
  id = PeriConstants::getNextID();
  mesh = 0x0;
  // to be implemented
}

PointMassd::~PointMassd() {
  while(neighborhood->getSize())
    delete neighborhood->removeLast();
  delete mesh;
  delete neighborhood;
}

void PointMassd::performPhysicsStep(double dt) {
  // to be implemented
}

double PointMassd::getDistTo(PointMassd* other) {
  Vec3d dist = position - other->position;
  return dist.mag();
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
Voxeld* PointMassd::getMesh() { return mesh; }
Vec3d PointMassd::getOriginalPosition() { return originalPosition; }
double PointMassd::getRadius() { return radius; }
double PointMassd::getVolume() { return volume; }
int PointMassd::getID() { return id; }

void PointMassd::setNeighborhood(Array<Springd*>* param) { neighborhood = param; }
void PointMassd::setMesh(Voxeld* param) { mesh = param; }
void PointMassd::setOriginalPosition(Vec3d param) { originalPosition = param; }
void PointMassd::setRadius(double param) { radius = param; }
void PointMassd::setVolume(double param) { volume = param; }
void PointMassd::setID(int param) { id = param; }
