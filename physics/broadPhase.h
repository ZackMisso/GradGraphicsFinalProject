#ifndef __BROADPHASE_H__
#define __BROADPHASE_H__

// this phase detects all possible collisions

#include "../dataStructures/array.h"
#include "physicsWorld.h"
#include "manifold.h"

class BroadPhase {
private:
public:
  BroadPhase();
  ~BroadPhase();
  virtual Array<Manifoldf*>* detectCollisionsf(PhysicsWorld* world);
  virtual Array<Manifoldd*>* detectCollisionsd(PhysicsWorld* world);
};

#endif
