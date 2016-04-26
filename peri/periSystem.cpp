#include "periSystem.h"

PeriSystemf::PeriSystemf() {
  pointMasses = new Array<PointMassf*>();
  springs = new Array<Springf*>();
  // to be implemented
}

PeriSystemf::PeriSystemf(TriMesh* mesh) {
  pointMasses = new Array<PointMassf*>();
  springs = new Array<Springf*>();
  // to be implemented
}

PeriSystemf::~PeriSystemf() {
  while(pointMasses->getSize())
    delete pointMasses->removeLast();
  while(springs->getSize())
    delete springs->removeLast();
  delete pointMasses;
  delete springs;
}

void PeriSystemf::preprocess() {
  createAllSprings();
  // to be implemented
}

void PeriSystemf::createAllSprings() {
  // to be implemented
}

void PeriSystemf::update() {
  // to be implemented
}

Array<PointMassf*>* PeriSystemf::getPointMasses() { return pointMasses; }
Array<Springf*>* PeriSystemf::getSprings() { return springs; }

void PeriSystemf::setPointMasses(Array<PointMassf*>* param) { pointMasses = param; }
void PeriSystemf::setSprings(Array<Springf*>* param) { springs = param; }

/////////////////////////// DOUBLE VERSION //////////////////////////////

PeriSystemd::PeriSystemd() {
  pointMasses = new Array<PointMassd*>();
  springs = new Array<Springd*>();
  // to be implemented
}

PeriSystemd::PeriSystemd(TriMesh* mesh) {
  pointMasses = new Array<PointMassd*>();
  springs = new Array<Springd*>();
  // to be implemented
}

PeriSystemd::~PeriSystemd() {
  while(pointMasses->getSize())
    delete pointMasses->removeLast();
  while(springs->getSize())
    delete springs->removeLast();
  delete pointMasses;
  delete springs;
}

void PeriSystemd::preprocess() {
  createAllSprings();
  // to be implemented
}

void PeriSystemd::createAllSprings() {
  // to be implemented
}

void PeriSystemd::update() {
  // to be implemented
}

Array<PointMassd*>* PeriSystemd::getPointMasses() { return pointMasses; }
Array<Springd*>* PeriSystemd::getSprings() { return springs; }

void PeriSystemd::setPointMasses(Array<PointMassd*>* param) { pointMasses = param; }
void PeriSystemd::setSprings(Array<Springd*>* param) { springs = param; }
