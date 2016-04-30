#ifndef __BROADPHASE_H__
#define __BROADPHASE_H__

// this phase detects all possible collisions

#include "../dataStructures/array.h"
#include "physicsBody.h"
#include "collision.h"

class BroadPhase {
private:
public:
  BroadPhase();
  ~BroadPhase();
  Array<Collisionf*>* detectCollisions(Array<PhysicsBodyf*>* bodies);
  Array<Collisiond*>* detectCollisions(Array<PhysicsBodyd*>* bodies);
};

#endif
