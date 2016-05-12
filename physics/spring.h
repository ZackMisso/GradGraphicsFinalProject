#ifndef __SPRING_H__
#define __SPRING_H__

#include "../math/vec3.h"
#include "../render/renderInclude.h"

class Springf {
private:
  int oneID;
  int twoID;
  void* oneRef;
  void* twoRef;
  float restLength;
  float springConstant;
  Vec3f firstRestPosition;
  Vec3f secondRestPosition;
  Vec3f firstPosition; // may not need
  Vec3f secondPosition; // may not need
  Vec3f currentPotential;
  Vec3f currentForce;
  //Vec3f currentRestPosition;
  bool isPeriSpring;
public:
  Springf(int param,int param2);
  ~Springf();
  void calculatePotential();
  void calculateSpringPotential();
  void calculatePeriPotential();
  bool isEqual(int one,int two);
  void render();
  // getter methods
  int getOneID();
  int getTwoID();
  void* getOneRef();
  void* getTwoRef();
  float getRestLength();
  float getSpringConstant();
  Vec3f getFirstRestPosition();
  Vec3f getSecondRestPosition();
  Vec3f getFirstPosition();
  Vec3f getSecondPosition();
  Vec3f getCurrentPotential();
  Vec3f getCurrentForce();
  //Vec3f getCurrentRestPosition();
  bool getIsPeriSpring();
  // setter methods
  void setOneID(int param);
  void setTwoID(int param);
  void setOneRef(void* param);
  void setTwoRef(void* param);
  void setRestLength(float param);
  void setSpringConstant(float param);
  void setFirstRestPosition(Vec3f param);
  void setSecondRestPosition(Vec3f param);
  void setFirstPosition(Vec3f param);
  void setSecondPosition(Vec3f param);
  void setCurrentPotential(Vec3f param);
  void setCurrentForce(Vec3f param);
  //void setCurrentRestPosition(Vec3f param);
  bool setIsPeriSpring(bool param);
};

class Springd {
private:
  int oneID;
  int twoID;
  void* oneRef;
  void* twoRef;
  double restLength;
  double springConstant;
  Vec3d firstRestPosition;
  Vec3d secondRestPosition;
  Vec3d firstPosition;
  Vec3d secondPosition;
  Vec3d currentPotential;
  Vec3d currentForce;
  bool isPeriSpring;
public:
  Springd(int param,int param2);
  ~Springd();
  void calculatePotential();
  void calculateSpringPotential();
  void calculatePeriPotential();
  bool isEqual(int one,int two);
  void render();
  // getter methods
  int getOneID();
  int getTwoID();
  void* getOneRef();
  void* getTwoRef();
  double getRestLength();
  double getSpringConstant();
  Vec3d getFirstRestPosition();
  Vec3d getSecondRestPosition();
  Vec3d getFirstPosition();
  Vec3d getSecondPosition();
  Vec3d getCurrentPotential();
  Vec3d getCurrentForce();
  bool getIsPeriSpring();
  // setter methods
  void setOneID(int param);
  void setTwoID(int param);
  void setOneRef(void* param);
  void setTwoRef(void* param);
  void setRestLength(double param);
  void setSpringConstant(double param);
  void setFirstRestPosition(Vec3d param);
  void setSecondRestPosition(Vec3d param);
  void setFirstPosition(Vec3d param);
  void setSecondPosition(Vec3d param);
  void setCurrentPotential(Vec3d param);
  void setCurrentForce(Vec3d param);
  void setIsPeriSpring(bool param);
};

#endif
