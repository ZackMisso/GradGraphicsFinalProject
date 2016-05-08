#ifndef __NAIVENARROWPHASE_H__
#define __NAIVENARROWPHASE_H__

#include "narrowPhase.h"

class NaiveNarrowPhase : public NarrowPhase {
public:
  virtual Array<Manifoldf*>* collisionChecksf(Array<Manifoldf*>* collisions);
  virtual Array<Manifoldd*>* collisionChecksd(Array<Manifoldd*>* collisions);
  virtual Array<Manifoldf*>* collisionResolutionf(Array<Manifoldf*>* collisions);
  virtual Array<Manifoldd*>* collisionResolutiond(Array<Manifoldd*>* collisions);
};

#endif
