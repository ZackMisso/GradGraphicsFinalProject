#include "spring.h"
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include "../peri/pointMass.h"

Springf::Springf(int param,int param2) {
  oneID = param;
  twoID = param;
  oneRef = 0x0;
  twoRef = 0x0;
  currentPotential = Vec3f();
  firstRestPosition = Vec3f();
  secondRestPosition = Vec3f();
}

Springf::~Springf() {
  oneRef = 0x0;
  twoRef = 0x0;
}

void Springf::calculatePotential() {
  PointMassf* onePos = (PointMassf*)oneRef;
  PointMassf* twoPos = (PointMassf*)twoRef;
  // to be implemented
}

bool Springf::isEqual(int one,int two) {
  if(oneID == one && twoID == two)
    return true;
  if(twoID == one && oneID == two)
    return true;
  return false;
}

void Springf::render() {
  PointMassf* onePos = (PointMassf*)oneRef;
  PointMassf* twoPos = (PointMassf*)twoRef;
  glBegin(GL_LINES);
  glVertex3f(onePos->getPosition()[0],onePos->getPosition()[1],onePos->getPosition()[2]);
  glVertex3f(twoPos->getPosition()[0],twoPos->getPosition()[1],twoPos->getPosition()[2]);
  glEnd();
}

int Springf::getOneID() { return oneID; }
int Springf::getTwoID() { return twoID; }
void* Springf::getOneRef() { return oneRef; }
void* Springf::getTwoRef() { return twoRef; }
float Springf::getRestLength() { return restLength; }
Vec3f Springf::getFirstRestPosition() { return firstRestPosition; }
Vec3f Springf::getSecondRestPosition() { return secondRestPosition; }
Vec3f Springf::getCurrentPotential() { return currentPotential; }

void Springf::setOneID(int param) { oneID = param; }
void Springf::setTwoID(int param) { twoID = param; }
void Springf::setOneRef(void* param) { oneRef = param; }
void Springf::setTwoRef(void* param) { twoRef = param; }
void Springf::setRestLength(float param) { restLength = param; }
void Springf::setFirstRestPosition(Vec3f param) { firstRestPosition = param; }
void Springf::setSecondRestPosition(Vec3f param) { secondRestPosition = param; }
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
}

Springd::~Springd() {
  oneRef = 0x0;
  twoRef = 0x0;
}

void Springd::calculatePotential() {
  PointMassd* onePos = (PointMassd*)oneRef;
  PointMassd* twoPos = (PointMassd*)twoRef;
  // to be implemented
}

bool Springd::isEqual(int one,int two) {
  if(oneID == one && twoID == two)
    return true;
  if(twoID == one && oneID == two)
    return true;
  return false;
}

void Springd::render() {
  PointMassd* onePos = (PointMassd*)oneRef;
  PointMassd* twoPos = (PointMassd*)twoRef;
  glBegin(GL_LINES);
  glVertex3f(onePos->getPosition()[0],onePos->getPosition()[1],onePos->getPosition()[2]);
  glVertex3f(twoPos->getPosition()[0],twoPos->getPosition()[1],twoPos->getPosition()[2]);
  glEnd();
}

int Springd::getOneID() { return oneID; }
int Springd::getTwoID() { return twoID; }
void* Springd::getOneRef() { return oneRef; }
void* Springd::getTwoRef() { return twoRef; }
double Springd::getRestLength() { return restLength; }
Vec3d Springd::getFirstRestPosition() { return firstRestPosition; }
Vec3d Springd::getSecondRestPosition() { return secondRestPosition; }
Vec3d Springd::getCurrentPotential() { return currentPotential; }

void Springd::setOneID(int param) { oneID = param; }
void Springd::setTwoID(int param) { twoID = param; }
void Springd::setOneRef(void* param) { oneRef = param; }
void Springd::setTwoRef(void* param) { twoRef = param; }
void Springd::setRestLength(double param) { restLength = param; }
void Springd::setFirstRestPosition(Vec3d param) { firstRestPosition = param; }
void Springd::setSecondRestPosition(Vec3d param) { secondRestPosition = param; }
void Springd::setCurrentPotential(Vec3d param) { currentPotential = param; }
