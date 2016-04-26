#ifndef __SPRING_H__
#define __SPRING_H__

#include "../math/vec3.h"
#include "../peri/pointMass.h"

class Springf {
private:
  PointMassf* one;
  PointMassf* two;
  float restLength;
  Vec3f currentPotential;
public:
  Springf(PointMassf* param,PointMassf* param2);
  ~Springf();
  void calculatePotential();
  // getter methods
  PointMassf* getOne();
  PointMassf* getTwo();
  float getRestLength();
  Vec3f getCurrentPotential();
  // setter methods
  void setOne(PointMassf* param);
  void setTwo(PointMassf* param);
  void setRestLength(float param);
  void setCurrentPotential(Vec3f param);
};

class Springd {
private:
  PointMassd* one;
  PointMassd* two;
  double restLength;
  Vec3d currentPotential;
public:
  Springd(PointMassd* param,PointMassd* param2);
  ~Springd();
  void calculatePotential();
  // getter methods
  PointMassd* getOne();
  PointMassd* getTwo();
  double getRestLength();
  Vec3d getCurrentPotential();
  // setter methods
  void setOne(PointMassd* param);
  void setTwo(PointMassd* param);
  void setRestLength(double param);
  void setCurrentPotential(Vec3d param);
};

#endif
