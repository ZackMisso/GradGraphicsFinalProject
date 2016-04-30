#ifndef __PHYSICSOBJECT_H__
#define __PHYSICSOBJECT_H__

// still not sure if we need this or not

#include "../math/vec3.h"
#include "../dataStructures/array.h"

class PhysicsObjectf {
protected:
  Array<Vec3f*>* externalForces;
  Vec3f position;
  Vec3f velocity;
  float mass;
public:
  PhysicsObjectf();
  ~PhysicsObjectf();
  virtual void performPhysicsStep(float dt);
  // getter methods
  Array<Vec3f*>* getExternelForces();
  Vec3f getPosition();
  Vec3f getVelocity();
  float getMass();
  // setter methods
  void setExternelForces(Array<Vec3f*>* param);
  void setPosition(Vec3f param);
  void setVelocity(Vec3f param);
  void setMass(float param);
};

class PhysicsObjectd {
protected:
  Array<Vec3d*>* externalForces;
  Vec3d position;
  Vec3d velocity;
  double mass;
public:
  PhysicsObjectd();
  ~PhysicsObjectd();
  virtual void performPhysicsStep(double dt);
  // getter methods
  Array<Vec3d*>* getExternelForces();
  Vec3d getPosition();
  Vec3d getVelocity();
  double getMass();
  // setter methods
  void setExternelForces(Array<Vec3d*>* param);
  void setPosition(Vec3d param);
  void setVelocity(Vec3d param);
  void setMass(double param);
};

#endif
