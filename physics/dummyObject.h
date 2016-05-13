#ifndef __DUMMYOBJECT_H__
#define __DUMMYOBJECT_H__

#include "physicsObject.h"

class DummyObjectf : public PhysicsObjectf {
private:
  PhysicsObjectf* owner;
  Vec3f relativePosition;
  Vec3f relativeVelocity;
public:
  DummyObjectf(PhysicsObjectf* collidedWith,PhysicsObjectf* collider);
  virtual void performPhysicsStep(float dt);
  virtual void eulerIntegration(float dt);
  virtual void implicitIntegration(float dt);
  virtual Vec3f accumulateForces(float dt);
};

class DummyObjectd : public PhysicsObjectd {
private:
  PhysicsObjectd* owner;
  Vec3d relativePosition;
  Vec3d relativeVelocity;
public:
  DummyObjectd(PhysicsObjectd* collidedWith,PhysicsObjectd* collider);
  virtual void performPhysicsStep(double dt);
  virtual void eulerIntegration(double dt);
  virtual void implicitIntegration(double dt);
  virtual Vec3d accumulateForces(double dt);
};

#endif
