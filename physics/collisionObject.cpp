#include "collisionObject.h"

CollisionObject::CollisionObject() {
  object = 0x0;
  isPhysicsObject = false;
  isPhysicsBody = false;
  isPeriSystem = false;
}

CollisionObject::CollisionObject(void* param,bool obj,bool body,bool peri) {
  object = param;
  isPhysicsObject = obj;
  isPhysicsBody = body;
  isPeriSystem = peri;
}

CollisionObject::~CollisionObject() {
  object = 0x0;
}

void CollisionObject::falsifyAll() {
  isPhysicsBody = false;
  isPhysicsObject = false;
  isPeriSystem = false;
}

void* CollisionObject::getObject() { return object; }
bool CollisionObject::getIsPhysicsObject() { return isPhysicsObject; }
bool CollisionObject::getIsPhysicsBody() { return isPhysicsBody; }
bool CollisionObject::getIsPeriSystem() { return isPeriSystem; }
// setter methods
void CollisionObject::setObject(void* param) { object = param; }
void CollisionObject::setIsPhysicsObject(bool param) { isPhysicsObject = param; }
void CollisionObject::setIsPhysicsBody(bool param) { isPhysicsBody = param; }
void CollisionObject::setIsPeriSystem(bool param) { isPeriSystem = param; }
