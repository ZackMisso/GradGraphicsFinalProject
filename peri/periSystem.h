#ifndef __PERISYSTEM_H__
#define __PERISYSTEM_H__

#include "../dataStructures/array.h"
#include "../geometry/trimesh.h"
#include "../physics/spring.h"
#include "pointMass.h"

class PeriSystemf {
private:
  Array<PointMassf*>* pointMasses;
  Array<Springf*>* springs;
public:
  PeriSystemf();
  PeriSystemf(TriMesh* mesh);
  ~PeriSystemf();
  // methods
  void preprocess();
  void createAllSprings();
  void update();
  // getter methods
  Array<PointMassf*>* getPointMasses();
  Array<Springf*>* getSprings();
  // setter methods
  void setPointMasses(Array<PointMassf*>* param);
  void setSprings(Array<Springf*>* param);
};

class PeriSystemd {
private:
  Array<PointMassd*>* pointMasses;
  Array<Springd*>* springs;
public:
  PeriSystemd();
  PeriSystemd(TriMesh* mesh);
  ~PeriSystemd();
  // methods
  void preprocess();
  void createAllSprings();
  void update();
  // getter methods
  Array<PointMassd*>* getPointMasses();
  Array<Springd*>* getSprings();
  // setter methods
  void setPointMasses(Array<PointMassd*>* param);
  void setSprings(Array<Springd*>* param);
};

#endif
