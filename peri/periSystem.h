#ifndef __PERISYSTEM_H__
#define __PERISYSTEM_H__

#include "../dataStructures/array.h"
#include "../geometry/trimesh.h"
#include "../geometry/voxel.h"
#include "../physics/spring.h"
#include "../render/renderInclude.h"
#include "pointMass.h"

class PeriSystemf {
private:
  Array<PointMassf*>* pointMasses;
  Array<Springf*>* springs;
  float pointMassR; // radius
  float pointMassM; // mass
  float pointMassH; // horizon
  float springConstant;
  float springDamp;
  float springBreak;
public:
  PeriSystemf();
  PeriSystemf(TriMeshf* mesh);
  PeriSystemf(Array<Voxelf*>* voxelMesh);
  ~PeriSystemf();
  // methods
  void preprocess();
  void convertVoxelsToPoints(Array<Voxelf*>* voxels);
  void performPhysicsStep(float dt);
  void render(RenderMode rm,bool displaySprings);
  // getter methods
  Array<PointMassf*>* getPointMasses();
  Array<Springf*>* getSprings();
  float getPointMassR();
  float getPointMassM();
  float getPointMassH();
  float getSpringConstant();
  float getSpringDamp();
  float getSpringBreak();
  // setter methods
  void setPointMasses(Array<PointMassf*>* param);
  void setSprings(Array<Springf*>* param);
  void setPointMassR(float param);
  void setPointMassM(float param);
  void setPointMassH(float param);
  void setSpringConstant(float param);
  void setSpringDamp(float param);
  void setSpringBreak(float param);
};

class PeriSystemd {
private:
  Array<PointMassd*>* pointMasses;
  Array<Springd*>* springs;
  double pointMassR; // radius
  double pointMassM; // mass
  double pointMassH; // horizon
  double springConstant;
  double springDamp;
  double springBreak;
public:
  PeriSystemd();
  PeriSystemd(TriMeshd* mesh);
  PeriSystemd(Array<Voxeld*>* voxelMesh);
  ~PeriSystemd();
  // methods
  void preprocess();
  void convertVoxelsToPoints(Array<Voxeld*>* voxels);
  void performPhysicsStep(double dt);
  void render(RenderMode rm,bool displaySprings);
  // getter methods
  Array<PointMassd*>* getPointMasses();
  Array<Springd*>* getSprings();
  double getPointMassR();
  double getPointMassM();
  double getPointMassH();
  double getSpringConstant();
  double getSpringDamp();
  double getSpringBreak();
  // setter methods
  void setPointMasses(Array<PointMassd*>* param);
  void setSprings(Array<Springd*>* param);
  void setPointMassR(double param);
  void setPointMassM(double param);
  void setPointMassH(double param);
  void setSpringConstant(double param);
  void setSpringDamp(double param);
  void setSpringBreak(double param);
};

#endif
