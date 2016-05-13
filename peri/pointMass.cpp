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

float PointMassf::getDistTo(PointMassf* other) {
  Vec3f dist = position - other->position;
  return dist.mag();
}

float PointMassf::getSqrDistTo(PointMassf* other) {
  Vec3f dist = position - other->position;
  return dist.sqrMag();
}

Vec3f PointMassf::accumulateForces(float dt) {
  //cout << "YEA" << endl;
  Vec3f totalForce = Vec3f();
  for(int i=0;i<externalForces->getSize();i++) {
    totalForce = totalForce + *(externalForces->get(i));
  }
  for(int i=0;i<getCollisionForces()->getSize();i++) {
    Vec3f force = getCollisionForces()->get(i)->getForceForObject((void*)this);
    // spring dampening
    float dampC = getCollisionForces()->get(i)->getDampConstant();
    force = force - Vec3f(dampC*getVelocity()[0],dampC*getVelocity()[1],dampC*getVelocity()[2]);
    // acumulate dampened force
    totalForce = totalForce + force;
  }
  for(int i=0;i<neighborhood->getSize();i++) {
    // THIS WILL NEED TO BE
    Vec3f force = neighborhood->get(i)->getForceForObject((void*)this);
    // spring dampening
    float dampC = neighborhood->get(i)->getDampConstant();
    force = force - Vec3f(dampC*getVelocity()[0],dampC*getVelocity()[1],dampC*getVelocity()[2]);
    totalForce = totalForce + force;
  }
  //cout << "TotalForce: ";
  //totalForce.debug();
  return totalForce;
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
int PointMassf::getID() { return id; }

void PointMassf::setNeighborhood(Array<Springf*>* param) { neighborhood = param; }
void PointMassf::setOriginalPosition(Vec3f param) { originalPosition = param; }
void PointMassf::setRadius(float param) { radius = param; }
void PointMassf::setVolume(float param) { volume = param; }
void PointMassf::setID(int param) { id = param; }

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

double PointMassd::getDistTo(PointMassd* other) {
  Vec3d dist = position - other->position;
  return dist.mag();
}

double PointMassd::getSqrDistTo(PointMassd* other) {
  Vec3d dist = position - other->position;
  return dist.sqrMag();
}

Vec3d PointMassd::accumulateForces(double dt) {
  //cout << "YEA" << endl;
  Vec3d totalForce = Vec3d();
  for(int i=0;i<externalForces->getSize();i++) {
    totalForce = totalForce + *(externalForces->get(i));
  }
  for(int i=0;i<getCollisionForces()->getSize();i++) {
    Vec3d force = getCollisionForces()->get(i)->getForceForObject((void*)this);
    // spring dampening
    double dampC = getCollisionForces()->get(i)->getDampConstant();
    force = force - Vec3d(dampC*getVelocity()[0],dampC*getVelocity()[1],dampC*getVelocity()[2]);
    // acumulate dampened force
    totalForce = totalForce + force;
  }
  for(int i=0;i<neighborhood->getSize();i++) {
    // THIS WILL NEED TO BE
    Vec3d force = neighborhood->get(i)->getForceForObject((void*)this);
    // spring dampening
    double dampC = neighborhood->get(i)->getDampConstant();
    force = force - Vec3d(dampC*getVelocity()[0],dampC*getVelocity()[1],dampC*getVelocity()[2]);
    totalForce = totalForce + force;
  }
  return totalForce;
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
int PointMassd::getID() { return id; }

void PointMassd::setNeighborhood(Array<Springd*>* param) { neighborhood = param; }
void PointMassd::setOriginalPosition(Vec3d param) { originalPosition = param; }
void PointMassd::setRadius(double param) { radius = param; }
void PointMassd::setVolume(double param) { volume = param; }
void PointMassd::setID(int param) { id = param; }
