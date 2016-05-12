#include "dummyObject.h"

DummyObjectf::DummyObjectf(PhysicsObjectf* collidedWith,PhysicsObjectf* collider) {
  setPosition(collider->getPosition());
  owner = collidedWith;
  setIsDummy(true);
}

void DummyObjectf::performPhysicsStep(float dt) {
  // to be implemented
}

void DummyObjectf::eulerIntegration(float dt) {
  // to be implemented
}

void DummyObjectf::implicitIntegration(float dt) {
  // to be implemented
}

Vec3f DummyObjectf::accumulateForces(float dt) {
  return Vec3f();
}

//////////////////// DOUBLE VERSION //////////////////////////

DummyObjectd::DummyObjectd(PhysicsObjectd* collidedWith,PhysicsObjectd* collider) {
  // to be implemented
}

void DummyObjectd::performPhysicsStep(double dt) {
  // to be implemented
}

void DummyObjectd::eulerIntegration(double dt) {
  // to be implemented
}

void DummyObjectd::implicitIntegration(double dt) {
  // to be implemented
}

Vec3d DummyObjectd::accumulateForces(double dt) {
  return Vec3d();
}
