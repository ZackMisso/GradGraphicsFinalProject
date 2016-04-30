#ifndef __COLLISION_H__
#define __COLLISION_H__

#include "physicsObject.h"

class Collisionf {
private:
  PhysicsObjectf* one;
  PhysicsObjectf* two;
public:
  Collisionf();
  Collisionf(PhysicsObjectf* a,PhysicsObjectf* b);
  ~Collisionf();
  // getter methods
  PhysicsObjectf* getOne();
  PhysicsObjectf* getTwo();
  // setter methods
  void setOne(PhysicsObjectf* param);
  void setTwo(PhysicsObjectf* param);
};

class Collisiond {
private:
  PhysicsObjectd* one;
  PhysicsObjectd* two;
public:
  Collisiond();
  Collisiond(PhysicsObjectd* a,PhysicsObjectd* b);
  ~Collisiond();
  // getter methods
  PhysicsObjectd* getOne();
  PhysicsObjectd* getTwo();
  // setter methods
  void setOne(PhysicsObjectd* param);
  void setTwo(PhysicsObjectd* param);
};

#endif
