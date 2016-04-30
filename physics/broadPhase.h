#ifndef __BROADPHASE_H__
#define __BROADPHASE_H_

// this phase detects all possible collisions

#include "../dataStructures/array.h"
#include "physicsObject.h"
#include "collision.h"

class BroadPhase {
private:
public:
  BroadPhase();
  ~BroadPhase();
  Array<Collisionf*>* detectCollisions(Array<PhysicsObjectf*>* objects);
  Array<Collisiond*>* detectCollisions(Array<PhysicsObjectd*>* objects);
};

#endif
