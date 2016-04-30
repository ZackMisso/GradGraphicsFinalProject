#ifndef __SPRING_H__
#define __SPRING_H__

#include "../math/vec3.h"

class Springf {
private:
  int oneID;
  int twoID;
  float restLength;
  Vec3f firstPosition;
  Vec3f secondPosition;
  Vec3f currentPotential;
public:
  Springf(int param,int param2);
  ~Springf();
  void calculatePotential();
  // getter methods
  int getOneID();
  int getTwoID();
  float getRestLength();
  Vec3f getFirstPosition();
  Vec3f getSecondPosition();
  Vec3f getCurrentPotential();
  // setter methods
  void setOneID(int param);
  void setTwoID(int param);
  void setRestLength(float param);
  void setFirstPosition(Vec3f param);
  void setSecondPosition(Vec3f param);
  void setCurrentPotential(Vec3f param);
};

class Springd {
private:
  int oneID;
  int twoID;
  double restLength;
  Vec3d firstPosition;
  Vec3d secondPosition;
  Vec3d currentPotential;
public:
  Springd(int param,int param2);
  ~Springd();
  void calculatePotential();
  // getter methods
  int getOneID();
  int getTwoID();
  double getRestLength();
  Vec3d getFirstPosition();
  Vec3d getSecondPosition();
  Vec3d getCurrentPotential();
  // setter methods
  void setOneID(int param);
  void setTwoID(int param);
  void setRestLength(double param);
  void setFirstPosition(Vec3d param);
  void setSecondPosition(Vec3d param);
  void setCurrentPotential(Vec3d param);
};

#endif
