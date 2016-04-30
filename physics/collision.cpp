#include "collision.h"

Collisionf::Collisionf() {
  one = 0x0;
  two = 0x0;
}

Collisionf::Collisionf(PhysicsObjectf* a,PhysicsObjectf* b) {
  one = a;
  two = b;
}

Collisionf::~Collisionf() {
  one = 0x0;
  two = 0x0;
}

PhysicsObjectf* Collisionf::getOne() { return one; }
PhysicsObjectf* Collisionf::getTwo() { return two; }

void Collisionf::setOne(PhysicsObjectf* param) { one = param; }
void Collisionf::setTwo(PhysicsObjectf* param) { two = param; }

///////////////////////// DOUBLE VERSION //////////////////////////

Collisiond::Collisiond() {
  one = 0x0;
  two = 0x0;
}

Collisiond::Collisiond(PhysicsObjectd* a,PhysicsObjectd* b) {
  one = a;
  two = b;
}

Collisiond::~Collisiond() {
  one = 0x0;
  two = 0x0;
}

PhysicsObjectd* Collisiond::getOne() { return one; }
PhysicsObjectd* Collisiond::getTwo() { return two; }

void Collisiond::setOne(PhysicsObjectd* param) { one = param; }
void Collisiond::setTwo(PhysicsObjectd* param) { two = param; }
