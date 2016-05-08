#include "naiveNarrowPhase.h"

// naive narrow phase assumes collisions are only between peri-systems
// and physics objects

Array<Manifoldf*>* NaiveNarrowPhase::collisionResolutionf(Array<Manifoldf*>* collisions) {
  // create the needed array
  Array<Manifoldf*>* manifolds = new Array<Manifoldf*>();
  for(int i=0;i<collisions->getSize();i++) {
    // continue implementation
  }
  // to be implemented
  return manifolds;
}

Array<Manifoldd*>* NaiveNarrowPhase::collisionResolutiond(Array<Manifoldd*>* collisions) {
  // to be implemented
  return 0x0;
}
