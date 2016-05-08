#ifndef __NARROWPHASE_H__
#define __NARROWPHASE_H__

// handles collision resolution

#include "../dataStructures/array.h"
#include "manifold.h"

class NarrowPhase {
private:
public:
  NarrowPhase();
  ~NarrowPhase();
  virtual Array<Manifoldf*>* collisionResolutionf(Array<Manifoldf*>* collisions);
  virtual Array<Manifoldd*>* collisionResolutiond(Array<Manifoldd*>* collisions);
};

#endif
