#ifndef __PERISYSTEM_H__
#define __PERISYSTEM_H__

#include "../dataStructures/array.h"
#include "../geometry/trimesh.h"
#include "pointMass.h"

class PeriSystemf {
private:
  Array<PointMassf*>* pointMasses;
public:
  PeriSystemf();
  PeriSystemf(TriMesh* mesh);
  ~PeriSystemf();
  // methods
  void update();
};

class PeriSystemd {
private:
  Array<PointMassd*>* pointMasses;
public:
  PeriSystemd();
  PeriSystemd(TriMesh* mesh);
  ~PeriSystemd();
  // methods
  void update();
};

#endif
