#ifndef __BROADPHASE_H__
#define __BROADPHASE_H__

// this phase detects all possible collisions

#include "../dataStructures/array.h"
#include "physicsBody.h"
#include "manifold.h"

class BroadPhase {
private:
public:
  BroadPhase();
  ~BroadPhase();
  virtual Array<Manifoldf*>* detectCollisions(Array<PhysicsBodyf*>* bodies);
  virtual Array<Manifoldd*>* detectCollisions(Array<PhysicsBodyd*>* bodies);
};

#endif
