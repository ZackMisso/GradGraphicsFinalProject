#include "periSystem.h"

PeriSystemf::PeriSystemf() {
  pointMasses = new Array<PointMassf*>();
  // to be implemented
}

PeriSystemf::PeriSystemf(TriMesh* mesh) {
  pointMasses = new Array<PointMassf*>();
  // to be implemented
}

PeriSystemf::~PeriSystemf() {
  while(pointMasses->getSize())
    delete pointMasses->removeLast();
  delete pointMasses;
}

void PeriSystemf::update() {
  // to be implemented
}

/////////////////////////// DOUBLE VERSION //////////////////////////////

PeriSystemd::PeriSystemd() {
  pointMasses = new Array<PointMassd*>();
  // to be implemented
}

PeriSystemd::PeriSystemd(TriMesh* mesh) {
  pointMasses = new Array<PointMassd*>();
  // to be implemented
}

PeriSystemd::~PeriSystemd() {
  while(pointMasses->getSize())
    delete pointMasses->removeLast();
  delete pointMasses;
}

void PeriSystemd::update() {
  // to be implemented
}
