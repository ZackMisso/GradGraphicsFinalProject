#include "bakedPhysicsObject.h"

#include <iostream>
using namespace std;

BakedPhysicsObjectf::BakedPhysicsObjectf() {
  positions = new Array<Vec3f*>();
}

BakedPhysicsObjectf::~BakedPhysicsObjectf() {
  while(positions->getSize())
    delete positions->removeLast();
  delete positions;
}

void BakedPhysicsObjectf::render(int frame, RenderMode rm) {
  geometry->updatePosition(*positions->get(frame));
  geometry->render(rm);
}

Array<Vec3f*>* BakedPhysicsObjectf::getPositions() { return positions; }

void BakedPhysicsObjectf::setPositions(Array<Vec3f*>* param) { positions = param; }

/////////////////// DOUBLE VERSION ///////////////////

BakedPhysicsObjectd::BakedPhysicsObjectd() {
  positions = new Array<Vec3d*>();
}

BakedPhysicsObjectd::~BakedPhysicsObjectd() {
  while(positions->getSize())
    delete positions->removeLast();
  delete positions;
}

void BakedPhysicsObjectd::render(int frame, RenderMode rm) {
  geometry->updatePosition(*positions->get(frame));
  cout << "waht" << endl;
  geometry->render(rm);
}

Array<Vec3d*>* BakedPhysicsObjectd::getPositions() { return positions; }

void BakedPhysicsObjectd::setPositions(Array<Vec3d*>* param) { positions = param; }
