#ifndef __SPRING_H__
#define __SPRING_H__

#include "../math/vec3.h"

class Springf {
private:
  int oneID;
  int twoID;
  void* oneRef;
  void* twoRef;
  float restLength;
  Vec3f firstRestPosition;
  Vec3f secondRestPosition;
  Vec3f firstPosition; // may not need
  Vec3f secondPosition; // may not need
  Vec3f currentPotential;
public:
  Springf(int param,int param2);
  ~Springf();
  void calculatePotential();
  bool isEqual(int one,int two);
  // getter methods
  int getOneID();
  int getTwoID();
  void* getOneRef();
  void* getTwoRef();
  float getRestLength();
  Vec3f getFirstRestPosition();
  Vec3f getSecondRestPosition();
  Vec3f getFirstPosition();
  Vec3f getSecondPosition();
  Vec3f getCurrentPotential();
  // setter methods
  void setOneID(int param);
  void setTwoID(int param);
  void setOneRef(void* param);
  void setTwoRef(void* param);
  void setRestLength(float param);
  void setFirstRestPosition(Vec3f param);
  void setSecondRestPosition(Vec3f param);
  void setFirstPosition(Vec3f param);
  void setSecondPosition(Vec3f param);
  void setCurrentPotential(Vec3f param);
};

class Springd {
private:
  int oneID;
  int twoID;
  void* oneRef;
  void* twoRef;
  double restLength;
  Vec3d firstRestPosition;
  Vec3d secondRestPosition;
  Vec3d firstPosition;
  Vec3d secondPosition;
  Vec3d currentPotential;
public:
  Springd(int param,int param2);
  ~Springd();
  void calculatePotential();
  bool isEqual(int one,int two);
  // getter methods
  int getOneID();
  int getTwoID();
  void* getOneRef();
  void* getTwoRef();
  double getRestLength();
  Vec3d getFirstRestPosition();
  Vec3d getSecondRestPosition();
  Vec3d getFirstPosition();
  Vec3d getSecondPosition();
  Vec3d getCurrentPotential();
  // setter methods
  void setOneID(int param);
  void setTwoID(int param);
  void setOneRef(void* param);
  void setTwoRef(void* param);
  void setRestLength(double param);
  void setFirstRestPosition(Vec3d param);
  void setSecondRestPosition(Vec3d param);
  void setFirstPosition(Vec3d param);
  void setSecondPosition(Vec3d param);
  void setCurrentPotential(Vec3d param);
};

#endif
