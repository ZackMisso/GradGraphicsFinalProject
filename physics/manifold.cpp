#include "manifold.h"

Manifoldf::Manifoldf() {
  one = 0x0;
  two = 0x0;
  contactPoint = Vec3f();
  collisionNormal = Vec3f();
  penetrationDepth = 0.0f;
  hasCollided = false;
}

Manifoldf::Manifoldf(PhysicsObjectf* a,PhysicsObjectf* b) {
  one = a;
  two = b;
  contactPoint = Vec3f();
  collisionNormal = Vec3f();
  penetrationDepth = 0.0f;
  hasCollided = false;
}

Manifoldf::~Manifoldf() {
  one = 0x0;
  two = 0x0;
}

void Manifoldf::process() {
  // to be implemented
}

PhysicsObjectf* Manifoldf::getOne() { return one; }
PhysicsObjectf* Manifoldf::getTwo() { return two; }
Vec3f Manifoldf::getContactPoint() { return contactPoint; }
Vec3f Manifoldf::getCollisionNormal() { return collisionNormal; }
float Manifoldf::getPenetrationDepth() { return penetrationDepth; }
bool Manifoldf::getHasCollided() { return hasCollided; }

void Manifoldf::setOne(PhysicsObjectf* param) { one = param; }
void Manifoldf::setTwo(PhysicsObjectf* param) { two = param; }
void Manifoldf::setContactPoint(Vec3f param) { contactPoint = param; }
void Manifoldf::setCollisionNormal(Vec3f param) { collisionNormal = param; }
void Manifoldf::setPenetrationDepth(float param) { penetrationDepth = param; }
void Manifoldf::setHasCollided(bool param) { hasCollided = param; }

///////////////////////// DOUBLE VERSION //////////////////////////

Manifoldd::Manifoldd() {
  one = 0x0;
  two = 0x0;
  contactPoint = Vec3d();
  collisionNormal = Vec3d();
  penetrationDepth = 0.0;
  hasCollided = false;
}

Manifoldd::Manifoldd(PhysicsObjectd* a,PhysicsObjectd* b) {
  one = a;
  two = b;
  contactPoint = Vec3d();
  collisionNormal = Vec3d();
  penetrationDepth = 0.0;
  hasCollided = false;
}

Manifoldd::~Manifoldd() {
  one = 0x0;
  two = 0x0;
}

PhysicsObjectd* Manifoldd::getOne() { return one; }
PhysicsObjectd* Manifoldd::getTwo() { return two; }
Vec3d Manifoldd::getContactPoint() { return contactPoint; }
Vec3d Manifoldd::getCollisionNormal() { return collisionNormal; }
double Manifoldd::getPenetrationDepth() { return penetrationDepth; }
bool Manifoldd::getHasCollided() { return hasCollided; }

void Manifoldd::setOne(PhysicsObjectd* param) { one = param; }
void Manifoldd::setTwo(PhysicsObjectd* param) { two = param; }
void Manifoldd::setContactPoint(Vec3d param) { contactPoint = param; }
void Manifoldd::setCollisionNormal(Vec3d param) { collisionNormal = param; }
void Manifoldd::setPenetrationDepth(double param) { penetrationDepth = param; }
void Manifoldd::setHasCollided(bool param) { hasCollided = param; }
