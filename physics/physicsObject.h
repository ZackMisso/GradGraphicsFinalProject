#ifndef __PHYSICSOBJECT_H__
#define __PHYSICSOBJECT_H__

// represents anything that has its own separate physics

#include "../math/vec3.h"
#include "../dataStructures/array.h"
#include "../geometry/geometry.h"
#include "spring.h"

class PhysicsObjectf {
protected:
  Array<Springf*>* collisionForces;
  Array<Vec3f*>* externalForces;
  Geometryf* geometry;
  Vec3f position;
  Vec3f velocity;
  float mass;
  bool noForce;
public:
  PhysicsObjectf();
  ~PhysicsObjectf();
  virtual void performPhysicsStep(float dt);
  virtual void eulerIntegration(float dt);
  virtual Vec3f accumulateForces(float dt);
  // getter methods
  Array<Springf*>* getCollisionForces();
  Array<Vec3f*>* getExternelForces();
  Geometryf* getGeometry();
  Vec3f getPosition();
  Vec3f getVelocity();
  float getMass();
  bool getNoForce();
  // setter methods
  void setCollisionForces(Array<Springf*>* param);
  void setExternelForces(Array<Vec3f*>* param);
  void setGeometry(Geometryf* param);
  void setPosition(Vec3f param);
  void setVelocity(Vec3f param);
  void setMass(float param);
  void setNoForce(bool param);
};

class PhysicsObjectd {
protected:
  Array<Springd*>* collisionForces;
  Array<Vec3d*>* externalForces;
  Geometryd* geometry;
  Vec3d position;
  Vec3d velocity;
  double mass;
  bool noForce;
public:
  PhysicsObjectd();
  ~PhysicsObjectd();
  virtual void performPhysicsStep(double dt);
  virtual void eulerIntegration(double dt);
  virtual Vec3d accumulateForces(double dt);
  // getter methods
  Array<Springd*>* getCollisionForces();
  Array<Vec3d*>* getExternelForces();
  Geometryd* getGeometry();
  Vec3d getPosition();
  Vec3d getVelocity();
  double getMass();
  bool getNoForce();
  // setter methods
  void setCollisionForces(Array<Springd*>* param);
  void setExternelForces(Array<Vec3d*>* param);
  void setGeometry(Geometryd* param);
  void setPosition(Vec3d param);
  void setVelocity(Vec3d param);
  void setMass(double param);
  void setNoForce(bool param);
};

#endif
