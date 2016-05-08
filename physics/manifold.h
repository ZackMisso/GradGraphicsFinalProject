#ifndef __MANIFOLD_H__
#define __MANIFOLD_H__

#include "physicsObject.h"

class Manifoldf {
private:
  PhysicsObjectf* one;
  PhysicsObjectf* two;
  Vec3f contactPoint;
  Vec3f collisionNormal;
  float penetrationDepth;
  bool hasCollided;
public:
  Manifoldf();
  Manifoldf(PhysicsObjectf* a,PhysicsObjectf* b);
  ~Manifoldf();
  // physics methods
  void process();
  // getter methods
  PhysicsObjectf* getOne();
  PhysicsObjectf* getTwo();
  Vec3f getContactPoint();
  Vec3f getCollisionNormal();
  float getPenetrationDepth();
  bool getHasCollided();
  // setter methods
  void setOne(PhysicsObjectf* param);
  void setTwo(PhysicsObjectf* param);
  void setContactPoint(Vec3f param);
  void setCollisionNormal(Vec3f param);
  void setPenetrationDepth(float param);
  void setHasCollided(bool param);
};

class Manifoldd {
private:
  PhysicsObjectd* one;
  PhysicsObjectd* two;
  Vec3d contactPoint;
  Vec3d collisionNormal;
  double penetrationDepth;
  bool hasCollided;
public:
  Manifoldd();
  Manifoldd(PhysicsObjectd* a,PhysicsObjectd* b);
  ~Manifoldd();
  // physics methods
  void process();
  // getter methods
  PhysicsObjectd* getOne();
  PhysicsObjectd* getTwo();
  Vec3d getContactPoint();
  Vec3d getCollisionNormal();
  double getPenetrationDepth();
  bool getHasCollided();
  // setter methods
  void setOne(PhysicsObjectd* param);
  void setTwo(PhysicsObjectd* param);
  void setContactPoint(Vec3d param);
  void setCollisionNormal(Vec3d param);
  void setPenetrationDepth(double param);
  void setHasCollided(bool param);
};

#endif
