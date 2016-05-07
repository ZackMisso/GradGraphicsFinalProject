#ifndef __PERISYSTEM_H__
#define __PERISYSTEM_H__

#include "../dataStructures/array.h"
#include "../geometry/trimesh.h"
#include "../geometry/voxel.h"
#include "../physics/spring.h"
#include "pointMass.h"

class PeriSystemf {
private:
  Array<PointMassf*>* pointMasses;
  Array<Springf*>* springs;
  float pointMassR; // radius
  float pointMassM; // mass
  float pointMassH; // horizon
public:
  PeriSystemf();
  PeriSystemf(TriMeshf* mesh);
  PeriSystemf(Array<Voxelf*>* voxelMesh);
  ~PeriSystemf();
  // methods
  void preprocess();
  void convertVoxelsToPoints(Array<Voxelf*>* voxels);
  void update();
  // getter methods
  Array<PointMassf*>* getPointMasses();
  Array<Springf*>* getSprings();
  float getPointMassR();
  float getPointMassM();
  float getPointMassH();
  // setter methods
  void setPointMasses(Array<PointMassf*>* param);
  void setSprings(Array<Springf*>* param);
  void setPointMassR(float param);
  void setPointMassM(float param);
  void setPointMassH(float param);
};

class PeriSystemd {
private:
  Array<PointMassd*>* pointMasses;
  Array<Springd*>* springs;
  double pointMassR; // radius
  double pointMassM; // mass
  double pointMassH; // horizon
public:
  PeriSystemd();
  PeriSystemd(TriMeshd* mesh);
  PeriSystemd(Array<Voxeld*>* voxelMesh);
  ~PeriSystemd();
  // methods
  void preprocess();
  void convertVoxelsToPoints(Array<Voxeld*>* voxels);
  void update();
  // getter methods
  Array<PointMassd*>* getPointMasses();
  Array<Springd*>* getSprings();
  double getPointMassR();
  double getPointMassM();
  double getPointMassH();
  // setter methods
  void setPointMasses(Array<PointMassd*>* param);
  void setSprings(Array<Springd*>* param);
  void setPointMassR(double param);
  void setPointMassM(double param);
  void setPointMassH(double param);
};

#endif
