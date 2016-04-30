#include "spring.h"

Springf::Springf(int param,int param2) {
  oneID = param;
  twoID = param;
  currentPotential = Vec3f();
  firstPosition = Vec3f();
  secondPosition = Vec3f();
  // TODO :: fix this
  //Vec3f tmp = one->getOriginalPosition() - two->getOriginalPosition();
  //restLength = tmp.mag();
}

Springf::~Springf() {
  //one = 0x0;
  //two = 0x0;
}

void Springf::calculatePotential() {
  // to be implemented
}

int Springf::getOneID() { return oneID; }
int Springf::getTwoID() { return twoID; }
float Springf::getRestLength() { return restLength; }
Vec3f Springf::getFirstPosition() { return firstPosition; }
Vec3f Springf::getSecondPosition() { return secondPosition; }
Vec3f Springf::getCurrentPotential() { return currentPotential; }

void Springf::setOneID(int param) { oneID = param; }
void Springf::setTwoID(int param) { twoID = param; }
void Springf::setRestLength(float param) { restLength = param; }
void Springf::setFirstPosition(Vec3f param) { firstPosition = param; }
void Springf::setSecondPosition(Vec3f param) { secondPosition = param; }
void Springf::setCurrentPotential(Vec3f param) { currentPotential = param; }

//////////////////////// DOUBLE VERSION //////////////////////////

Springd::Springd(int param,int param2) {
  oneID = param;
  twoID = param;
  currentPotential = Vec3d();
  firstPosition = Vec3d();
  secondPosition = Vec3d();
  // TODO :: fix this
  //Vec3d tmp = one->getOriginalPosition() - two->getOriginalPosition();
  //restLength = tmp.mag();
}

Springd::~Springd() {
  //one = 0x0;
  //two = 0x0;
}

void Springd::calculatePotential() {
  // to be implemented
}

int Springd::getOneID() { return oneID; }
int Springd::getTwoID() { return twoID; }
double Springd::getRestLength() { return restLength; }
Vec3d Springd::getFirstPosition() { return firstPosition; }
Vec3d Springd::getSecondPosition() { return secondPosition; }
Vec3d Springd::getCurrentPotential() { return currentPotential; }

void Springd::setOneID(int param) { oneID = param; }
void Springd::setTwoID(int param) { twoID = param; }
void Springd::setRestLength(double param) { restLength = param; }
void Springd::setFirstPosition(Vec3d param) { firstPosition = param; }
void Springd::setSecondPosition(Vec3d param) { secondPosition = param; }
void Springd::setCurrentPotential(Vec3d param) { currentPotential = param; }
