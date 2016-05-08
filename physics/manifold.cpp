#include "manifold.h"

Manifoldf::Manifoldf() {
  one = new CollisionObject();
  two = new CollisionObject();
  contactPoint = Vec3f();
  collisionNormal = Vec3f();
  penetrationDepth = 0.0f;
  hasCollided = false;
}

Manifoldf::Manifoldf(CollisionObject* a,CollisionObject* b) {
  one = a;
  two = b;
  contactPoint = Vec3f();
  collisionNormal = Vec3f();
  penetrationDepth = 0.0f;
  hasCollided = false;
}

Manifoldf::~Manifoldf() {
  delete one;
  delete two;
}

void Manifoldf::process() {
  // to be implemented
}

CollisionObject* Manifoldf::getOne() { return one; }
CollisionObject* Manifoldf::getTwo() { return two; }
Vec3f Manifoldf::getContactPoint() { return contactPoint; }
Vec3f Manifoldf::getCollisionNormal() { return collisionNormal; }
float Manifoldf::getPenetrationDepth() { return penetrationDepth; }
bool Manifoldf::getHasCollided() { return hasCollided; }

void Manifoldf::setOne(CollisionObject* param) { one = param; }
void Manifoldf::setTwo(CollisionObject* param) { two = param; }
void Manifoldf::setContactPoint(Vec3f param) { contactPoint = param; }
void Manifoldf::setCollisionNormal(Vec3f param) { collisionNormal = param; }
void Manifoldf::setPenetrationDepth(float param) { penetrationDepth = param; }
void Manifoldf::setHasCollided(bool param) { hasCollided = param; }

///////////////////////// DOUBLE VERSION //////////////////////////

Manifoldd::Manifoldd() {
  one = new CollisionObject();
  two = new CollisionObject();
  contactPoint = Vec3d();
  collisionNormal = Vec3d();
  penetrationDepth = 0.0;
  hasCollided = false;
}

Manifoldd::Manifoldd(CollisionObject* a,CollisionObject* b) {
  one = a;
  two = b;
  contactPoint = Vec3d();
  collisionNormal = Vec3d();
  penetrationDepth = 0.0;
  hasCollided = false;
}

Manifoldd::~Manifoldd() {
  delete one;
  delete two;
}

CollisionObject* Manifoldd::getOne() { return one; }
CollisionObject* Manifoldd::getTwo() { return two; }
Vec3d Manifoldd::getContactPoint() { return contactPoint; }
Vec3d Manifoldd::getCollisionNormal() { return collisionNormal; }
double Manifoldd::getPenetrationDepth() { return penetrationDepth; }
bool Manifoldd::getHasCollided() { return hasCollided; }

void Manifoldd::setOne(CollisionObject* param) { one = param; }
void Manifoldd::setTwo(CollisionObject* param) { two = param; }
void Manifoldd::setContactPoint(Vec3d param) { contactPoint = param; }
void Manifoldd::setCollisionNormal(Vec3d param) { collisionNormal = param; }
void Manifoldd::setPenetrationDepth(double param) { penetrationDepth = param; }
void Manifoldd::setHasCollided(bool param) { hasCollided = param; }
