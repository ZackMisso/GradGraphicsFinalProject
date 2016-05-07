#ifndef __PHYSICSOBJECT_H__
#define __PHYSICSOBJECT_H__

// represents anything that has its own separate physics

#include "../math/vec3.h"
#include "../dataStructures/array.h"

class PhysicsObjectf {
protected:
  Array<Vec3f*>* externalForces;
  Vec3f position;
  Vec3f velocity;
  float mass;
  bool noForce;
public:
  PhysicsObjectf();
  ~PhysicsObjectf();
  virtual void performPhysicsStep(float dt);
  // getter methods
  Array<Vec3f*>* getExternelForces();
  Vec3f getPosition();
  Vec3f getVelocity();
  float getMass();
  bool getNoForce();
  // setter methods
  void setExternelForces(Array<Vec3f*>* param);
  void setPosition(Vec3f param);
  void setVelocity(Vec3f param);
  void setMass(float param);
  void setNoForce(bool param);
};

class PhysicsObjectd {
protected:
  Array<Vec3d*>* externalForces;
  Vec3d position;
  Vec3d velocity;
  double mass;
  bool noForce;
public:
  PhysicsObjectd();
  ~PhysicsObjectd();
  virtual void performPhysicsStep(double dt);
  // getter methods
  Array<Vec3d*>* getExternelForces();
  Vec3d getPosition();
  Vec3d getVelocity();
  double getMass();
  bool getNoForce();
  // setter methods
  void setExternelForces(Array<Vec3d*>* param);
  void setPosition(Vec3d param);
  void setVelocity(Vec3d param);
  void setMass(double param);
  void setNoForce(bool param);
};

#endif
