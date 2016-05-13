#include "spring.h"
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include "../peri/pointMass.h"
#include "dummyObject.h"
#include <iostream>

using namespace std;

Springf::Springf(void* one,void* two) {
  //oneID = -1;
  //twoID = -1;
  oneRef = one;
  twoRef = two;
  springConstant = 0.0f;
  breakForce = 100.0f;
  dampConstant = 0.05f;
  periRadius = 0.05f;
  repulseConstant = 0.9f;
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
  isBroken = false;
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
  repulseConstant = 0.9f;
  periRadius = 0.05f;
  currentPotential = Vec3f();
  currentPotential = Vec3f();
  currentForce = Vec3f();
  currentRestPosition = Vec3f();
  firstRestPosition = Vec3f();
  secondRestPosition = Vec3f();
  isPeriSpring = false;
  isCollisionSpring = false;
  isBroken = false;
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
    //cout << "SON OF A BITCH" << endl;
    if(isBroken) {
      return;
    }
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
    if(isBroken) {
      return;
    }
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
  if(isBroken) {
    return;
  } if(isCollisionSpring) {
    Vec3f dPos = firstPosition - secondPosition;
    currentForce[0] = springConstant * dPos[0];
    currentForce[1] = springConstant * dPos[1];
    currentForce[2] = springConstant * dPos[2];
  } else {
    // define x as one and x' as two
    //cout << "Calculating Peri Force" << endl;
    Vec3f n = Vec3f();
    Vec3f zet = Vec3f();
    Vec3f u = Vec3f();
    Vec3f up = Vec3f();
    Vec3f fnz = Vec3f();
    //float g = 1.0f;
    u = firstPosition - firstRestPosition;
    up = secondPosition - secondRestPosition;
    n = u - up;
    zet = firstPosition - secondPosition;
    fnz = n + zet;
    float strain = ((n+zet).mag() - zet.mag()) / zet.mag();
    float mag = (n+zet).mag();
    fnz[0] = fnz[0]/mag;
    fnz[1] = fnz[1]/mag;
    fnz[2] = fnz[2]/mag;
    Vec3f rep = Vec3f();
    float tmp = 1.0f * (secondPosition - firstPosition).mag();
    float tmp2 = 1.35f*(periRadius*2.0f);
    float ds = tmp < tmp2 ? tmp : tmp2;
    if(ds < 0.0f) {
      cout << "WHATATATAT" << endl;
    }
    //rep[0] = fnz[0]*springConstant*(mag-ds);
    //rep[1] = fnz[1]*springConstant*(mag-ds);
    //rep[2] = fnz[2]*springConstant*(mag-ds);
    float factor = (restLength-mag) > 0.0f ? (restLength-mag) : 0.0f;
    factor *= repulseConstant;
    rep[0] = fnz[0]*springConstant*factor;
    rep[1] = fnz[1]*springConstant*factor;
    rep[2] = fnz[2]*springConstant*factor;
    fnz[0] = springConstant * strain * fnz[0];
    fnz[1] = springConstant * strain * fnz[1];
    fnz[2] = springConstant * strain * fnz[2];
    //fnz[0] = strain * fnz[0];
    //fnz[1] = strain * fnz[1];
    //fnz[2] = strain * fnz[2];
    // add repulsive force
    fnz[0] = fnz[0] - rep[0];
    fnz[1] = fnz[1] - rep[1];
    fnz[2] = fnz[2] - rep[2];
    currentForce[0] = fnz[0];
    currentForce[1] = fnz[1];
    currentForce[2] = fnz[2];
  }
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
  //cout << "HELLO" << endl;
  //if(oneRef == 0x0)
  //  cout << "WHAT One?" << endl;
  //if(twoRef == 0x0)
  //  cout << "What Two?" << endl;
  //if(oneRef != 0x0 && twoRef != 0x0) {
    PhysicsObjectf* one = (PhysicsObjectf*)oneRef;
    PhysicsObjectf* two = (PhysicsObjectf*)twoRef;
    firstPosition = one->getPosition();
    secondPosition = two->getPosition();
  //}
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
    if((firstPosition-secondPosition).mag() > 1.25f*restLength || (firstPosition-secondPosition).mag() < 0.75f*restLength) {
      isBroken = true;
    }
    // to be implemented
  }
  return false;
}

Vec3f Springf::getForceForObject(void* obj) {
  //cout << "CurrentForce: ";
  //currentForce.debug();
  if(isBroken) {
    return Vec3f();
  } if(obj != oneRef) {
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
  if(isCollisionSpring) {
    if(twoRef == two)
      return true;
  } else {
    if(oneRef == one && twoRef == two)
      return true;
    if(twoRef == one && oneRef == two)
      return true;
  }
  return false;
}

void Springf::render(RenderMode rm) {
  PointMassf* onePos = (PointMassf*)oneRef;
  PointMassf* twoPos = (PointMassf*)twoRef;
  if(isBroken) {
    //cout << "IT IS BROKEN" << endl;
  //if((firstPosition-secondPosition).mag() > 1.25f*restLength
  //    || (firstPosition-secondPosition).mag() < 0.75f*restLength) {
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_LINES);
    glVertex3f(onePos->getPosition()[0],onePos->getPosition()[1],onePos->getPosition()[2]);
    glVertex3f(twoPos->getPosition()[0],twoPos->getPosition()[1],twoPos->getPosition()[2]);
    glEnd();
  } else {
    glBegin(GL_LINES);
    glVertex3f(onePos->getPosition()[0],onePos->getPosition()[1],onePos->getPosition()[2]);
    glVertex3f(twoPos->getPosition()[0],twoPos->getPosition()[1],twoPos->getPosition()[2]);
    glEnd();
  }
}

int Springf::getOneID() { return oneID; }
int Springf::getTwoID() { return twoID; }
void* Springf::getOneRef() { return oneRef; }
void* Springf::getTwoRef() { return twoRef; }
float Springf::getRestLength() { return restLength; }
float Springf::getSpringConstant() { return springConstant; }
float Springf::getBreakForce() { return breakForce; }
float Springf::getDampConstant() { return dampConstant; }
float Springf::getPeriRadius() { return periRadius; }
float Springf::getRepulseConstant() { return repulseConstant; }
Vec3f Springf::getFirstRestPosition() { return firstRestPosition; }
Vec3f Springf::getSecondRestPosition() { return secondRestPosition; }
Vec3f Springf::getCurrentPotential() { return currentPotential; }
Vec3f Springf::getCurrentForce() { return currentForce; }
Vec3f Springf::getCurrentRestPosition() { return currentRestPosition; }
Vec3f Springf::getCurrentDampForce() { return currentDampForce; }
bool Springf::getIsPeriSpring() { return isPeriSpring; }
bool Springf::getIsCollisionSpring() { return isCollisionSpring; }
bool Springf::getIsBroken() { return isBroken; }

void Springf::setOneID(int param) { oneID = param; }
void Springf::setTwoID(int param) { twoID = param; }
void Springf::setOneRef(void* param) { oneRef = param; }
void Springf::setTwoRef(void* param) { twoRef = param; }
void Springf::setRestLength(float param) { restLength = param; }
void Springf::setSpringConstant(float param) { springConstant = param; }
void Springf::setBreakForce(float param) { breakForce = param; }
void Springf::setDampConstant(float param) { dampConstant = param; }
void Springf::setPeriRadius(float param) { periRadius = param; }
void Springf::setRepulseConstant(float param) { repulseConstant = param; }
void Springf::setFirstRestPosition(Vec3f param) { firstRestPosition = param; }
void Springf::setSecondRestPosition(Vec3f param) { secondRestPosition = param; }
void Springf::setCurrentPotential(Vec3f param) { currentPotential = param; }
void Springf::setCurrentForce(Vec3f param) { currentForce = param; }
void Springf::setCurrentRestPosition(Vec3f param) { currentRestPosition = param; }
void Springf::setCurrentDampForce(Vec3f param) { currentDampForce = param; }
void Springf::setIsPeriSpring(bool param) { isPeriSpring = param; }
void Springf::setIsCollisionSpring(bool param) { isCollisionSpring = param; }
void Springf::setIsBroken(bool param) { isBroken = param; }

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
  periRadius = 0.05;
  repulseConstant = 0.9;
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
  isBroken = false;
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
  periRadius = 0.05;
  repulseConstant = 0.9;
  currentDampForce = Vec3d();
  isCollisionSpring = false;
  isBroken = false;
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
    if(isBroken) {
      return;
    }
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
    if(isBroken) {
      return;
    }
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
  if(isCollisionSpring) {
    Vec3d dPos = firstPosition - secondPosition;
    currentForce[0] = springConstant * dPos[0];
    currentForce[1] = springConstant * dPos[1];
    currentForce[2] = springConstant * dPos[2];
  } else {
    // define x as one and x' as two
    //cout << "Calculating Peri Force" << endl;
    Vec3d n = Vec3d();
    Vec3d zet = Vec3d();
    Vec3d u = Vec3d();
    Vec3d up = Vec3d();
    Vec3d fnz = Vec3d();
    //float g = 1.0f;
    u = firstPosition - firstRestPosition;
    up = secondPosition - secondRestPosition;
    n = u - up;
    zet = firstPosition - secondPosition;
    fnz = n + zet;
    double strain = ((n+zet).mag() - zet.mag()) / zet.mag();
    double mag = (n+zet).mag();
    fnz[0] = fnz[0]/mag;
    fnz[1] = fnz[1]/mag;
    fnz[2] = fnz[2]/mag;
    Vec3d rep = Vec3d();
    double tmp = 1.0 * (secondPosition - firstPosition).mag();
    double tmp2 = 1.35*(periRadius*2.0);
    double ds = tmp < tmp2 ? tmp : tmp2;
    if(ds < 0.0) {
      cout << "WHATATATAT" << endl;
    }
    //rep[0] = fnz[0]*springConstant*(mag-ds);
    //rep[1] = fnz[1]*springConstant*(mag-ds);
    //rep[2] = fnz[2]*springConstant*(mag-ds);
    double factor = (restLength-mag) > 0.0 ? (restLength-mag) : 0.0;
    factor *= repulseConstant;
    rep[0] = fnz[0]*springConstant*factor;
    rep[1] = fnz[1]*springConstant*factor;
    rep[2] = fnz[2]*springConstant*factor;
    fnz[0] = springConstant * strain * fnz[0];
    fnz[1] = springConstant * strain * fnz[1];
    fnz[2] = springConstant * strain * fnz[2];
    //fnz[0] = strain * fnz[0];
    //fnz[1] = strain * fnz[1];
    //fnz[2] = strain * fnz[2];
    // add repulsive force
    fnz[0] = fnz[0] - rep[0];
    fnz[1] = fnz[1] - rep[1];
    fnz[2] = fnz[2] - rep[2];
    currentForce[0] = fnz[0];
    currentForce[1] = fnz[1];
    currentForce[2] = fnz[2];
  }
}

// this method assumes setCurrentPositions was called first
void Springd::calculateCurrentRestPosition() {
  // vector from one to two
  if(!isBroken) {
    Vec3d diff = secondPosition - firstPosition;
    diff.normalize();
    // set rest position relative to location of first object
    currentRestPosition[0] = diff[0] * restLength;
    currentRestPosition[1] = diff[1] * restLength;
    currentRestPosition[2] = diff[2] * restLength;
  }
}

void Springd::setCurrentPositions() {
  //cout << "HELLO" << endl;
  if(!isBroken) {
    PhysicsObjectd* one = (PhysicsObjectd*)oneRef;
    PhysicsObjectd* two = (PhysicsObjectd*)twoRef;
    firstPosition = one->getPosition();
    secondPosition = two->getPosition();
  }
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
      if((firstPosition-secondPosition).mag() > 1.25*restLength
          || (firstPosition-secondPosition).mag() < 0.75*restLength) {
        isBroken = true;
      }
  }
  return false;
}

Vec3d Springd::getForceForObject(void* obj) {
  //cout << "CurrentForce: ";
  //currentForce.debug();
  if(isBroken) {
    return Vec3d();
  }if(obj != oneRef) {
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
  if(isCollisionSpring) {
    if(twoRef == two)
      return true;
  } else {
    if(oneRef == one && twoRef == two)
      return true;
    if(twoRef == one && oneRef == two)
      return true;
  }
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
double Springd::getPeriRadius() { return periRadius; }
double Springd::getRepulseConstant() { return repulseConstant; }
Vec3d Springd::getFirstRestPosition() { return firstRestPosition; }
Vec3d Springd::getSecondRestPosition() { return secondRestPosition; }
Vec3d Springd::getCurrentPotential() { return currentPotential; }
Vec3d Springd::getCurrentForce() { return currentForce; }
Vec3d Springd::getCurrentRestPosition() { return currentRestPosition; }
Vec3d Springd::getCurrentDampForce() { return currentDampForce; }
bool Springd::getIsPeriSpring() { return isPeriSpring; }
bool Springd::getIsCollisionSpring() { return isCollisionSpring; }
bool Springd::getIsBroken() { return isBroken; }

void Springd::setOneID(int param) { oneID = param; }
void Springd::setTwoID(int param) { twoID = param; }
void Springd::setOneRef(void* param) { oneRef = param; }
void Springd::setTwoRef(void* param) { twoRef = param; }
void Springd::setRestLength(double param) { restLength = param; }
void Springd::setSpringConstant(double param) { springConstant = param; }
void Springd::setRepulseConstant(double param) { repulseConstant = param; }
void Springd::setBreakForce(double param) { breakForce = param; }
void Springd::setDampConstant(double param) { dampConstant = param; }
void Springd::setPeriRadius(double param) { periRadius = param; }
void Springd::setFirstRestPosition(Vec3d param) { firstRestPosition = param; }
void Springd::setSecondRestPosition(Vec3d param) { secondRestPosition = param; }
void Springd::setCurrentPotential(Vec3d param) { currentPotential = param; }
void Springd::setCurrentForce(Vec3d param) { currentForce = param; }
void Springd::setCurrentRestPosition(Vec3d param) { currentRestPosition = param; }
void Springd::setCurrentDampForce(Vec3d param) { currentDampForce = param; }
void Springd::setIsPeriSpring(bool param) { isPeriSpring = param; }
void Springd::setIsCollisionSpring(bool param) { isCollisionSpring = param; }
void Springd::setIsBroken(bool param) { isBroken = param; }
