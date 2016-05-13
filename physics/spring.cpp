#include "spring.h"
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include "../peri/pointMass.h"
#include "dummyObject.h"
#include <iostream>

using namespace std;

Springf::Springf(void* one,void* two) {
  oneID = -1;
  twoID = -1;
  oneRef = one;
  twoRef = two;
  springConstant = 0.0f;
  breakForce = 100.0f;
  dampConstant = 0.05f;
  currentPotential = Vec3f();
  currentForce = Vec3f();
  currentDampForce = Vec3f();
  PhysicsObjectf* oneRefP = (PhysicsObjectf*)one;
  PhysicsObjectf* twoRefP = (PhysicsObjectf*)two;
  firstRestPosition = oneRefP->getPosition();
  secondRestPosition = twoRefP->getPosition();
  currentRestPosition = secondRestPosition;
  firstPosition = firstRestPosition;
  secondPosition = secondRestPosition;
  restLength = (firstPosition - secondPosition).mag();
  //cout << "Rest Length: " << restLength << endl;
  //cout << "FirstRestPosition: ";
  //firstRestPosition.debug();
  //cout << "SecondRestPosition: ";
  //secondRestPosition.debug();
  isPeriSpring = false;
  isCollisionSpring = false;
  dummyCount = 0;
}

Springf::Springf(int param,int param2) {
  oneID = param;
  twoID = param;
  oneRef = 0x0;
  twoRef = 0x0;
  springConstant = 0.0f;
  breakForce = 10.0f;
  dampConstant = 0.05f;
  currentPotential = Vec3f();
  currentPotential = Vec3f();
  currentForce = Vec3f();
  currentRestPosition = Vec3f();
  firstRestPosition = Vec3f();
  secondRestPosition = Vec3f();
  isPeriSpring = false;
  isCollisionSpring = false;
  dummyCount = 0;
}

Springf::~Springf() {
  oneRef = 0x0;
  twoRef = 0x0;
}

// this method assumes calculateCurrentRestPositon was called first
void Springf::calculatePotential() {
  //PointMassf* onePos = (PointMassf*)oneRef;
  //PointMassf* twoPos = (PointMassf*)twoRef;
  if(isPeriSpring) {
    calculatePeriPotential();
  } else {
    calculateSpringPotential();
  }
}

// this method assumes calculateCurrentRestPositon was called first
void Springf::calculatePeriPotential() {
  // to be implemented
}

// this method assumes calculateCurrentRestPositon was called first
void Springf::calculateSpringPotential() {
  if(isCollisionSpring) {
    Vec3f dPos = firstPosition-secondPosition;
    Vec3f lastPotential = currentPotential;
    currentPotential[0] = springConstant * dPos[0] * dPos[0] * 0.5f;
    currentPotential[1] = springConstant * dPos[1] * dPos[1] * 0.5f;
    currentPotential[2] = springConstant * dPos[2] * dPos[2] * 0.5f;
    if(dummyCount == 0) {
      if(lastPotential.sqrMag() > currentPotential.sqrMag()) {
        dummyCount = 1;
      }
    } else if(dummyCount == 1) {
      if(lastPotential.sqrMag() < currentPotential.sqrMag()) {
        dummyCount = 2;
      }
    }
  } else {
  // idk if that is the right order or not
    Vec3f dPos = currentRestPosition - (secondPosition - firstPosition);
    currentPotential[0] = springConstant * dPos[0] * dPos[0] * 0.5f;
    currentPotential[1] = springConstant * dPos[1] * dPos[1] * 0.5f;
    currentPotential[2] = springConstant * dPos[2] * dPos[2] * 0.5f;
  }
}

void Springf::calculateForce() {
  if(isPeriSpring) {
    calculatePeriForce();
  } else {
    calculateSpringForce();
  }
}

// this method assumes calculateCurrentRestPositon was called first
void Springf::calculateSpringForce() {
  // displacement from rest position.
  // idk if that is the right order or not
  if(isCollisionSpring) {
    Vec3f dPos = firstPosition - secondPosition;
    currentForce[0] = springConstant * dPos[0];
    currentForce[1] = springConstant * dPos[1];
    currentForce[2] = springConstant * dPos[2];
  } else {
    Vec3f dPos = currentRestPosition - (secondPosition - firstPosition);
    //cout << "DPos: ";
    //dPos.debug();
    currentForce[0] = springConstant * dPos[0];
    currentForce[1] = springConstant * dPos[1];
    currentForce[2] = springConstant * dPos[2];
    //cout << "MainCurrentForce: ";
    //currentForce.debug();
  }
}

// this method assumes calculateCurrentRestPositon was called first
void Springf::calculatePeriForce() {
  // to be implemented
}

// this method assumes setCurrentPositions was called first
void Springf::calculateCurrentRestPosition() {
  // vector from one to two
  Vec3f diff = secondPosition - firstPosition;
  diff.normalize();
  // set rest position relative to location of first object
  currentRestPosition[0] = diff[0] * restLength;
  currentRestPosition[1] = diff[1] * restLength;
  currentRestPosition[2] = diff[2] * restLength;
  //cout << "Current Rest Position: ";
  //currentRestPosition.debug();
}

void Springf::setCurrentPositions() {
  PhysicsObjectf* one = (PhysicsObjectf*)oneRef;
  PhysicsObjectf* two = (PhysicsObjectf*)twoRef;
  firstPosition = one->getPosition();
  secondPosition = two->getPosition();
}

bool Springf::shouldDestroySpring() {
  if(isCollisionSpring) {
    //DummyObjectf* dummy = (DummyObjectf*)oneRef;
    //if(dummyCount == 4)
    //  return true;
    //if(dummyCount >= 2) // add an extra frame to avoid sinking
    //  dummyCount++;
    //return false;
    return dummyCount == 2;
  } else {
    // to be implemented
  }
  return false;
}

Vec3f Springf::getForceForObject(void* obj) {
  //cout << "CurrentForce: ";
  //currentForce.debug();
  if(obj != oneRef) {
    return currentForce;
  } else {
    Vec3f negForce = Vec3f() - currentForce;
    return negForce;
  }
}

bool Springf::isEqual(int one,int two) {
  if(oneID == one && twoID == two)
    return true;
  if(twoID == one && oneID == two)
    return true;
  return false;
}

bool Springf::isEqual(void* one,void* two) {
  if(oneRef == one && twoRef == two)
    return true;
  if(twoRef == one && oneRef == two)
    return true;
  return false;
}

void Springf::render(RenderMode rm) {
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
float Springf::getSpringConstant() { return springConstant; }
float Springf::getBreakForce() { return breakForce; }
float Springf::getDampConstant() { return dampConstant; }
Vec3f Springf::getFirstRestPosition() { return firstRestPosition; }
Vec3f Springf::getSecondRestPosition() { return secondRestPosition; }
Vec3f Springf::getCurrentPotential() { return currentPotential; }
Vec3f Springf::getCurrentForce() { return currentForce; }
Vec3f Springf::getCurrentRestPosition() { return currentRestPosition; }
Vec3f Springf::getCurrentDampForce() { return currentDampForce; }
bool Springf::getIsPeriSpring() { return isPeriSpring; }
bool Springf::getIsCollisionSpring() { return isCollisionSpring; }

void Springf::setOneID(int param) { oneID = param; }
void Springf::setTwoID(int param) { twoID = param; }
void Springf::setOneRef(void* param) { oneRef = param; }
void Springf::setTwoRef(void* param) { twoRef = param; }
void Springf::setRestLength(float param) { restLength = param; }
void Springf::setSpringConstant(float param) { springConstant = param; }
void Springf::setBreakForce(float param) { breakForce = param; }
void Springf::setDampConstant(float param) { dampConstant = param; }
void Springf::setFirstRestPosition(Vec3f param) { firstRestPosition = param; }
void Springf::setSecondRestPosition(Vec3f param) { secondRestPosition = param; }
void Springf::setCurrentPotential(Vec3f param) { currentPotential = param; }
void Springf::setCurrentForce(Vec3f param) { currentForce = param; }
void Springf::setCurrentRestPosition(Vec3f param) { currentRestPosition = param; }
void Springf::setCurrentDampForce(Vec3f param) { currentDampForce = param; }
void Springf::setIsPeriSpring(bool param) { isPeriSpring = param; }
void Springf::setIsCollisionSpring(bool param) { isCollisionSpring = param; }

//////////////////////// DOUBLE VERSION //////////////////////////

Springd::Springd(void* one,void* two) {
  oneID = -1;
  //cout << "CurrentForce: ";
  //currentForce.debug();
  twoID = -1;
  oneRef = one;
  twoRef = two;
  springConstant = 0.0;
  breakForce = 100.0;
  dampConstant = 0.05;
  currentPotential = Vec3d();
  currentForce = Vec3d();
  currentDampForce = Vec3d();
  PhysicsObjectd* oneRefP = (PhysicsObjectd*)one;
  PhysicsObjectd* twoRefP = (PhysicsObjectd*)two;
  firstRestPosition = oneRefP->getPosition();
  secondRestPosition = twoRefP->getPosition();
  currentRestPosition = secondRestPosition;
  firstPosition = firstRestPosition;
  secondPosition = secondRestPosition;
  restLength = (firstPosition - secondPosition).mag();
  isPeriSpring = false;
  isCollisionSpring = false;
  dummyCount = 0;
}

Springd::Springd(int param,int param2) {
  oneID = param;
  twoID = param;
  oneRef = 0x0;
  twoRef = 0x0;
  currentPotential = Vec3d();
  currentForce = Vec3d();
  currentRestPosition = Vec3d();
  firstRestPosition = Vec3d();
  secondRestPosition = Vec3d();
  isPeriSpring = false;
  springConstant = 0.0;
  breakForce = 0.0;
  dampConstant = 0.05;
  currentDampForce = Vec3d();
  isCollisionSpring = false;
  dummyCount = 0;
}

Springd::~Springd() {
  oneRef = 0x0;
  twoRef = 0x0;
}

// this method assumes calculateCurrentRestPositon was called first
void Springd::calculatePotential() {
  //PointMassd* onePos = (PointMassd*)oneRef;
  //PointMassd* twoPos = (PointMassd*)twoRef;
  if(isPeriSpring) {
    calculatePeriPotential();
  } else {
    calculateSpringPotential();
  }
}

// this method assumes calculateCurrentRestPositon was called first
void Springd::calculatePeriPotential() {
  // to be implemented
}

// this method assumes calculateCurrentRestPositon was called first
void Springd::calculateSpringPotential() {
  if(isCollisionSpring) {
    Vec3d dPos = firstPosition - secondPosition;
    Vec3d lastPotential = currentPotential;
    currentPotential[0] = springConstant * dPos[0] * dPos[0] * 0.5f;
    currentPotential[1] = springConstant * dPos[1] * dPos[1] * 0.5f;
    currentPotential[2] = springConstant * dPos[2] * dPos[2] * 0.5f;
    if(dummyCount == 0) {
      if(lastPotential.sqrMag() > currentPotential.sqrMag()) {
        dummyCount = 1;
      }
    } else if(dummyCount == 1) {
      if(lastPotential.sqrMag() < currentPotential.sqrMag()) {
        dummyCount = 2;
      }
    }
  } else {
  // idk if that is the right order or not
    Vec3d dPos = currentRestPosition - (secondPosition - firstPosition);
    currentPotential[0] = springConstant * dPos[0] * dPos[0] * 0.5f;
    currentPotential[1] = springConstant * dPos[1] * dPos[1] * 0.5f;
    currentPotential[2] = springConstant * dPos[2] * dPos[2] * 0.5f;
  }
}

// this method assumes calculateCurrentRestPositon was called first
void Springd::calculateForce() {
  if(isPeriSpring) {
    calculatePeriForce();
  } else {
    calculateSpringForce();
  }
}

// this method assumes calculateCurrentRestPositon was called first
void Springd::calculateSpringForce() {
  // displacement from rest position.
  if(isCollisionSpring) {
    Vec3d dPos = firstPosition - secondPosition;
    currentForce[0] = springConstant * dPos[0];
    currentForce[1] = springConstant * dPos[1];
    currentForce[2] = springConstant * dPos[2];
  } else {
  // idk if that is the right order or not
    Vec3d dPos = currentRestPosition - (secondPosition - firstPosition);
    currentForce[0] = springConstant * dPos[0];
    currentForce[1] = springConstant * dPos[1];
    currentForce[2] = springConstant * dPos[2];
  }
}

// this method assumes calculateCurrentRestPositon was called first
void Springd::calculatePeriForce() {
  // to be implemented
}

// this method assumes setCurrentPositions was called first
void Springd::calculateCurrentRestPosition() {
  // vector from one to two
  Vec3d diff = secondPosition - firstPosition;
  diff.normalize();
  // set rest position relative to location of first object
  currentRestPosition[0] = diff[0] * restLength;
  currentRestPosition[1] = diff[1] * restLength;
  currentRestPosition[2] = diff[2] * restLength;
}

void Springd::setCurrentPositions() {
  PhysicsObjectd* one = (PhysicsObjectd*)oneRef;
  PhysicsObjectd* two = (PhysicsObjectd*)twoRef;
  firstPosition = one->getPosition();
  secondPosition = two->getPosition();
}

bool Springd::shouldDestroySpring() {
  if(isCollisionSpring) {
    //DummyObjectf* dummy = (DummyObjectf*)oneRef;
    //if(dummyCount == 4)
    //  return true;
    //if(dummyCount >= 2) // add an extra frame to avoid sinking
    //  dummyCount++;
    //return false;
    return dummyCount == 2;
  } else {
    // to be implemented
  }
  return false;
}

Vec3d Springd::getForceForObject(void* obj) {
  //cout << "CurrentForce: ";
  //currentForce.debug();
  if(obj != oneRef) {
    return currentForce;
  } else {
    Vec3d negForce = Vec3d() - currentForce;
    return negForce;
  }
}

bool Springd::isEqual(int one,int two) {
  if(oneID == one && twoID == two)
    return true;
  if(twoID == one && oneID == two)
    return true;
  return false;
}

bool Springd::isEqual(void* one,void* two) {
  if(oneRef == one && twoRef == two)
    return true;
  if(twoRef == one && oneRef == two)
    return true;
  return false;
}

void Springd::render(RenderMode rm) {
  glBegin(GL_LINES);
  glVertex3f(firstPosition[0],firstPosition[1],firstPosition[2]);
  glVertex3f(secondPosition[0],secondPosition[1],secondPosition[2]);
  glEnd();
}

int Springd::getOneID() { return oneID; }
int Springd::getTwoID() { return twoID; }
void* Springd::getOneRef() { return oneRef; }
void* Springd::getTwoRef() { return twoRef; }
double Springd::getRestLength() { return restLength; }
double Springd::getSpringConstant() { return springConstant; }
double Springd::getBreakForce() { return breakForce; }
double Springd::getDampConstant() { return dampConstant; }
Vec3d Springd::getFirstRestPosition() { return firstRestPosition; }
Vec3d Springd::getSecondRestPosition() { return secondRestPosition; }
Vec3d Springd::getCurrentPotential() { return currentPotential; }
Vec3d Springd::getCurrentForce() { return currentForce; }
Vec3d Springd::getCurrentRestPosition() { return currentRestPosition; }
Vec3d Springd::getCurrentDampForce() { return currentDampForce; }
bool Springd::getIsPeriSpring() { return isPeriSpring; }
bool Springd::getIsCollisionSpring() { return isCollisionSpring; }

void Springd::setOneID(int param) { oneID = param; }
void Springd::setTwoID(int param) { twoID = param; }
void Springd::setOneRef(void* param) { oneRef = param; }
void Springd::setTwoRef(void* param) { twoRef = param; }
void Springd::setRestLength(double param) { restLength = param; }
void Springd::setSpringConstant(double param) { springConstant = param; }
void Springd::setBreakForce(double param) { breakForce = param; }
void Springd::setDampConstant(double param) { dampConstant = param; }
void Springd::setFirstRestPosition(Vec3d param) { firstRestPosition = param; }
void Springd::setSecondRestPosition(Vec3d param) { secondRestPosition = param; }
void Springd::setCurrentPotential(Vec3d param) { currentPotential = param; }
void Springd::setCurrentForce(Vec3d param) { currentForce = param; }
void Springd::setCurrentRestPosition(Vec3d param) { currentRestPosition = param; }
void Springd::setCurrentDampForce(Vec3d param) { currentDampForce = param; }
void Springd::setIsPeriSpring(bool param) { isPeriSpring = param; }
void Springd::setIsCollisionSpring(bool param) { isCollisionSpring = param; }
