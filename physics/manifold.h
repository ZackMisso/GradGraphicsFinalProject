#ifndef __MANIFOLD_H__
#define __MANIFOLD_H__

#include "physicsObject.h"
#include "collisionObject.h"

class Manifoldf {
private:
  CollisionObject* one;
  CollisionObject* two;
  Vec3f contactPoint;
  Vec3f collisionNormal;
  float penetrationDepth;
  bool hasCollided;
public:
  Manifoldf();
  Manifoldf(CollisionObject* a,CollisionObject* b);
  ~Manifoldf();
  // physics methods
  void process();
  // getter methods
  CollisionObject* getOne();
  CollisionObject* getTwo();
  Vec3f getContactPoint();
  Vec3f getCollisionNormal();
  float getPenetrationDepth();
  bool getHasCollided();
  // setter methods
  void setOne(CollisionObject* param);
  void setTwo(CollisionObject* param);
  void setContactPoint(Vec3f param);
  void setCollisionNormal(Vec3f param);
  void setPenetrationDepth(float param);
  void setHasCollided(bool param);
};

class Manifoldd {
private:
  CollisionObject* one;
  CollisionObject* two;
  Vec3d contactPoint;
  Vec3d collisionNormal;
  double penetrationDepth;
  bool hasCollided;
public:
  Manifoldd();
  Manifoldd(CollisionObject* a,CollisionObject* b);
  ~Manifoldd();
  // physics methods
  void process();
  // getter methods
  CollisionObject* getOne();
  CollisionObject* getTwo();
  Vec3d getContactPoint();
  Vec3d getCollisionNormal();
  double getPenetrationDepth();
  bool getHasCollided();
  // setter methods
  void setOne(CollisionObject* param);
  void setTwo(CollisionObject* param);
  void setContactPoint(Vec3d param);
  void setCollisionNormal(Vec3d param);
  void setPenetrationDepth(double param);
  void setHasCollided(bool param);
};

#endif
