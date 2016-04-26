#include "frame.h"

Framef::Framef() {
  pointMasses = new Array<BakePointMassf*>();
  otherTris = new Array<Trif*>();
  camera = new Cameraf();
}

Framef::~Framef() {
  while(pointMasses->getSize())
    delete pointMasses->removeLast();
  while(otherTris->getSize())
    delete otherTris->removeLast();
  delete camera;
  delete pointMasses;
  delete otherTris;
}

void Framef::display() {
  // to be implemented
}

Array<BakePointMassf*>* Framef::getPointMasses() { return pointMasses; }
Array<Trif*>* Framef::getOtherTris() { return otherTris; }
Cameraf* Framef::getCamera() { return camera; }
// setter methods
void Framef::setPointMasses(Array<BakePointMassf*>* param) { pointMasses = param; }
void Framef::setOtherTris(Array<Trif*>* param) { otherTris = param; }
void Framef::setCamera(Cameraf* param) { camera = param; }

////////////////////////// DOUBLE VERSION //////////////////////////

Framed::Framed() {
  pointMasses = new Array<BakePointMassd*>();
  otherTris = new Array<Trid*>();
  camera = new Camerad();
}

Framed::~Framed() {
  while(pointMasses->getSize())
    delete pointMasses->removeLast();
  while(otherTris->getSize())
    delete otherTris->removeLast();
  delete camera;
  delete pointMasses;
  delete otherTris;
}

void Framed::display() {
  // to be implemented
}

Array<BakePointMassd*>* Framed::getPointMasses() { return pointMasses; }
Array<Trid*>* Framed::getOtherTris() { return otherTris; }
Camerad* Framed::getCamera() { return camera; }
// setter methods
void Framed::setPointMasses(Array<BakePointMassd*>* param) { pointMasses = param; }
void Framed::setOtherTris(Array<Trid*>* param) { otherTris = param; }
void Framed::setCamera(Camerad* param) { camera = param; }
