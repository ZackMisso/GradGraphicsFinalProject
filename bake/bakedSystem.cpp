#include "bakedSystem.h"

BakedSystem::BakedSystem() {
  objectsf = new Array<BakedPhysicsObjectf*>();
  objectsd = new Array<BakedPhysicsObjectd*>();
}

BakedSystem::~BakedSystem() {
  while(objectsf->getSize())
    delete objectsf->removeLast();
  while(objectsd->getSize())
    delete objectsd->removeLast();
  delete objectsd;
  delete objectsf;
}

Array<BakedPhysicsObjectf*>* BakedSystem::getObjectsF() { return objectsf; }
Array<BakedPhysicsObjectd*>* BakedSystem::getObjectsD() { return objectsd; }

void BakedSystem::setObjectsF(Array<BakedPhysicsObjectf*>* param) { objectsf = param; }
void BakedSystem::setObjectsD(Array<BakedPhysicsObjectd*>* param) { objectsd = param; }
