#include "spring.h"

Springf::Springf(PointMassf* param,PointMassf* param2) {
  one = param;
  two = param;
  currentPotential = Vec3f();
  // TODO :: fix this
  //Vec3f tmp = one->getOriginalPosition() - two->getOriginalPosition();
  //restLength = tmp.mag();
}

Springf::~Springf() {
  one = 0x0;
  two = 0x0;
}

void Springf::calculatePotential() {
  // to be implemented
}

PointMassf* Springf::getOne() { return one; }
PointMassf* Springf::getTwo() { return two; }
float Springf::getRestLength() { return restLength; }
Vec3f Springf::getCurrentPotential() { return currentPotential; }

void Springf::setOne(PointMassf* param) { one = param; }
void Springf::setTwo(PointMassf* param) { two = param; }
void Springf::setRestLength(float param) { restLength = param; }
void Springf::setCurrentPotential(Vec3f param) { currentPotential = param; }

//////////////////////// DOUBLE VERSION //////////////////////////

Springd::Springd(PointMassd* param,PointMassd* param2) {
  one = param;
  two = param;
  currentPotential = Vec3d();
  // TODO :: fix this
  //Vec3d tmp = one->getOriginalPosition() - two->getOriginalPosition();
  //restLength = tmp.mag();
}

Springd::~Springd() {
  one = 0x0;
  two = 0x0;
}

void Springd::calculatePotential() {
  // to be implemented
}

PointMassd* Springd::getOne() { return one; }
PointMassd* Springd::getTwo() { return two; }
double Springd::getRestLength() { return restLength; }
Vec3d Springd::getCurrentPotential() { return currentPotential; }

void Springd::setOne(PointMassd* param) { one = param; }
void Springd::setTwo(PointMassd* param) { two = param; }
void Springd::setRestLength(double param) { restLength = param; }
void Springd::setCurrentPotential(Vec3d param) { currentPotential = param; }
