#include "spring.h"

Springf::Springf(int param,int param2) {
  oneID = param;
  twoID = param;
  oneRef = 0x0;
  twoRef = 0x0;
  currentPotential = Vec3f();
  firstRestPosition = Vec3f();
  secondRestPosition = Vec3f();
  firstPosition = Vec3f();
  secondPosition = Vec3f();
  // TODO :: fix this
  //Vec3f tmp = one->getOriginalPosition() - two->getOriginalPosition();
  //restLength = tmp.mag();
}

Springf::~Springf() {
  //one = 0x0;
  //two = 0x0;
  oneRef = 0x0;
  twoRef = 0x0;
}

void Springf::calculatePotential() {
  // to be implemented
}

bool Springf::isEqual(int one,int two) {
  if(oneID == one && twoID == two)
    return true;
  if(twoID == one && oneID == two)
    return true;
  return false;
}

int Springf::getOneID() { return oneID; }
int Springf::getTwoID() { return twoID; }
void* Springf::getOneRef() { return oneRef; }
void* Springf::getTwoRef() { return twoRef; }
float Springf::getRestLength() { return restLength; }
Vec3f Springf::getFirstRestPosition() { return firstRestPosition; }
Vec3f Springf::getSecondRestPosition() { return secondRestPosition; }
Vec3f Springf::getFirstPosition() { return firstPosition; }
Vec3f Springf::getSecondPosition() { return secondPosition; }
Vec3f Springf::getCurrentPotential() { return currentPotential; }

void Springf::setOneID(int param) { oneID = param; }
void Springf::setTwoID(int param) { twoID = param; }
void Springf::setOneRef(void* param) { oneRef = param; }
void Springf::setTwoRef(void* param) { twoRef = param; }
void Springf::setRestLength(float param) { restLength = param; }
void Springf::setFirstRestPosition(Vec3f param) { firstRestPosition = param; }
void Springf::setSecondRestPosition(Vec3f param) { secondRestPosition = param; }
void Springf::setFirstPosition(Vec3f param) { firstPosition = param; }
void Springf::setSecondPosition(Vec3f param) { secondPosition = param; }
void Springf::setCurrentPotential(Vec3f param) { currentPotential = param; }

//////////////////////// DOUBLE VERSION //////////////////////////

Springd::Springd(int param,int param2) {
  oneID = param;
  twoID = param;
  oneRef = 0x0;
  twoRef = 0x0;
  currentPotential = Vec3d();
  firstRestPosition = Vec3d();
  secondRestPosition = Vec3d();
  firstPosition = Vec3d();
  secondPosition = Vec3d();
  // TODO :: fix this
  //Vec3d tmp = one->getOriginalPosition() - two->getOriginalPosition();
  //restLength = tmp.mag();
}

Springd::~Springd() {
  //one = 0x0;
  //two = 0x0;
  oneRef = 0x0;
  twoRef = 0x0;
}

void Springd::calculatePotential() {
  // to be implemented
}

bool Springd::isEqual(int one,int two) {
  if(oneID == one && twoID == two)
    return true;
  if(twoID == one && oneID == two)
    return true;
  return false;
}

int Springd::getOneID() { return oneID; }
int Springd::getTwoID() { return twoID; }
void* Springd::getOneRef() { return oneRef; }
void* Springd::getTwoRef() { return twoRef; }
double Springd::getRestLength() { return restLength; }
Vec3d Springd::getFirstRestPosition() { return firstRestPosition; }
Vec3d Springd::getSecondRestPosition() { return secondRestPosition; }
Vec3d Springd::getFirstPosition() { return firstPosition; }
Vec3d Springd::getSecondPosition() { return secondPosition; }
Vec3d Springd::getCurrentPotential() { return currentPotential; }

void Springd::setOneID(int param) { oneID = param; }
void Springd::setTwoID(int param) { twoID = param; }
void Springd::setOneRef(void* param) { oneRef = param; }
void Springd::setTwoRef(void* param) { twoRef = param; }
void Springd::setRestLength(double param) { restLength = param; }
void Springd::setFirstRestPosition(Vec3d param) { firstRestPosition = param; }
void Springd::setSecondRestPosition(Vec3d param) { secondRestPosition = param; }
void Springd::setFirstPosition(Vec3d param) { firstPosition = param; }
void Springd::setSecondPosition(Vec3d param) { secondPosition = param; }
void Springd::setCurrentPotential(Vec3d param) { currentPotential = param; }
