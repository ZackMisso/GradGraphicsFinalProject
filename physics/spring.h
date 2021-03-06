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
  float breakForce;
  float springConstant;
  float dampConstant;
  float periRadius;
  float repulseConstant;
  Vec3f firstRestPosition;
  Vec3f secondRestPosition;
  Vec3f firstPosition; // may not need
  Vec3f secondPosition; // may not need
  Vec3f currentPotential;
  Vec3f currentForce;
  Vec3f currentRestPosition;
  Vec3f currentDampForce;
  bool isPeriSpring;
  bool isCollisionSpring;
  bool isBroken;
  int dummyCount;
public:
  Springf(void* one,void* two);
  Springf(int param,int param2);
  ~Springf();
  void calculatePotential();
  void calculateSpringPotential();
  void calculatePeriPotential();
  void calculateForce();
  void calculateSpringForce();
  void calculatePeriForce();
  void calculateCurrentRestPosition();
  void setCurrentPositions();
  bool shouldDestroySpring();
  Vec3f getForceForObject(void* obj);
  bool isEqual(int one,int two);
  bool isEqual(void* one,void* two);
  void render(RenderMode rm);
  // getter methods
  int getOneID();
  int getTwoID();
  void* getOneRef();
  void* getTwoRef();
  float getRestLength();
  float getSpringConstant();
  float getBreakForce();
  float getDampConstant();
  float getPeriRadius();
  float getRepulseConstant();
  Vec3f getFirstRestPosition();
  Vec3f getSecondRestPosition();
  Vec3f getFirstPosition();
  Vec3f getSecondPosition();
  Vec3f getCurrentPotential();
  Vec3f getCurrentForce();
  Vec3f getCurrentRestPosition();
  Vec3f getCurrentDampForce();
  bool getIsPeriSpring();
  bool getIsCollisionSpring();
  bool getIsBroken();
  // setter methods
  void setOneID(int param);
  void setTwoID(int param);
  void setOneRef(void* param);
  void setTwoRef(void* param);
  void setRestLength(float param);
  void setSpringConstant(float param);
  void setBreakForce(float param);
  void setDampConstant(float param);
  void setPeriRadius(float param);
  void setRepulseConstant(float param);
  void setFirstRestPosition(Vec3f param);
  void setSecondRestPosition(Vec3f param);
  void setFirstPosition(Vec3f param);
  void setSecondPosition(Vec3f param);
  void setCurrentPotential(Vec3f param);
  void setCurrentForce(Vec3f param);
  void setCurrentRestPosition(Vec3f param);
  void setCurrentDampForce(Vec3f param);
  void setIsPeriSpring(bool param);
  void setIsCollisionSpring(bool param);
  void setIsBroken(bool param);
};

class Springd {
private:
  int oneID;
  int twoID;
  void* oneRef;
  void* twoRef;
  double restLength;
  double springConstant;
  double breakForce;
  double dampConstant;
  double periRadius;
  double repulseConstant;
  Vec3d firstRestPosition;
  Vec3d secondRestPosition;
  Vec3d firstPosition;
  Vec3d secondPosition;
  Vec3d currentPotential;
  Vec3d currentForce;
  Vec3d currentRestPosition;
  Vec3d currentDampForce;
  bool isPeriSpring;
  bool isCollisionSpring;
  bool isBroken;
  int dummyCount;
public:
  Springd(void* one,void* two);
  Springd(int param,int param2);
  ~Springd();
  void calculatePotential();
  void calculateSpringPotential();
  void calculatePeriPotential();
  void calculateForce();
  void calculateSpringForce();
  void calculatePeriForce();
  void calculateCurrentRestPosition();
  void setCurrentPositions();
  bool shouldDestroySpring();
  Vec3d getForceForObject(void* obj);
  bool isEqual(int one,int two);
  bool isEqual(void* one,void* two);
  void render(RenderMode rm);
  // getter methods
  int getOneID();
  int getTwoID();
  void* getOneRef();
  void* getTwoRef();
  double getRestLength();
  double getSpringConstant();
  double getBreakForce();
  double getDampConstant();
  double getPeriRadius();
  double getRepulseConstant();
  Vec3d getFirstRestPosition();
  Vec3d getSecondRestPosition();
  Vec3d getFirstPosition();
  Vec3d getSecondPosition();
  Vec3d getCurrentPotential();
  Vec3d getCurrentForce();
  Vec3d getCurrentRestPosition();
  Vec3d getCurrentDampForce();
  bool getIsPeriSpring();
  bool getIsCollisionSpring();
  bool getIsBroken();
  // setter methods
  void setOneID(int param);
  void setTwoID(int param);
  void setOneRef(void* param);
  void setTwoRef(void* param);
  void setRestLength(double param);
  void setSpringConstant(double param);
  void setBreakForce(double param);
  void setDampConstant(double param);
  void setPeriRadius(double param);
  void setRepulseConstant(double param);
  void setFirstRestPosition(Vec3d param);
  void setSecondRestPosition(Vec3d param);
  void setFirstPosition(Vec3d param);
  void setSecondPosition(Vec3d param);
  void setCurrentPotential(Vec3d param);
  void setCurrentForce(Vec3d param);
  void setCurrentRestPosition(Vec3d param);
  void setCurrentDampForce(Vec3d param);
  void setIsPeriSpring(bool param);
  void setIsCollisionSpring(bool param);
  void setIsBroken(bool param);
};

#endif
