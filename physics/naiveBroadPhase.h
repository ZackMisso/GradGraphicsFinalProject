#ifndef __NAIVEBROADPHASE_H__
#define __NAIVEBROADPHASE_H

#include "broadPhase.h"

class NaiveBroadPhase : public BroadPhase {
public:
  virtual Array<Manifoldf*>* detectCollisions(Array<PhysicsBodyf*>* bodies);
  virtual Array<Manifoldd*>* detectCollisions(Array<PhysicsBodyd*>* bodies);
};

#endif
