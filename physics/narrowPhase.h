#ifndef __NARROWPHASE_H__
#define __NARROWPHASE_H__

// handles collision resolution

#include "../dataStructures/array.h"
#include "manifold.h"
#include "collision.h"

class NarrowPhase {
private:
public:
  NarrowPhase();
  ~NarrowPhase();
  Array<Manifoldf*>* collisionResolutionf(Array<Collisionf*>* collisions);
  Array<Manifoldd*>* collisionResolutiond(Array<Collisiond*>* collisions);
};

#endif
