#ifndef __CAMERA_H__
#define __CAMERA_H__

// camera object for perspective projections

#include "../math/vec3.h"
#include "../math/quat.h"

class Cameraf {
private:
  Quatf orientation;
  Vec3f position;
  Vec3f lookingAt;
  float fieldOfView;
  float aspectRatio;
  float near;
  float far;
public:
  Cameraf();
  Cameraf(float one,float two,float three,float four);
  void setUpProjection();
  // getter methods
  Quatf getOrientation();
  Vec3f getPosition();
  //Vec3f getLookingAt();
  float getFieldOfView();
  float getAspectRatio();
  float getNear();
  float getFar();
  // setter methods
  void setOrientation(Quatf param);
  void setPosition(Vec3f param);
  //void setLookingAt(Vec3f param);
  void setFieldOfView(float param);
  void setAspectRatio(float param);
  void setNear(float param);
  void setFar(float param);
};

class Camerad {
private:
  Quatd orientation;
  Vec3d position;
  //Vec3d lookingAt;
  double fieldOfView;
  double aspectRatio;
  double near;
  double far;
public:
  Camerad();
  Camerad(double one,double two,double three,double four);
  void setUpProjection();
  // getter methods
  Quatd getOrientation();
  Vec3d getPosition();
  //Vec3d getLookingAt();
  double getFieldOfView();
  double getAspectRatio();
  double getNear();
  double getFar();
  // setter methods
  void setOrientation(Quatd param);
  void setPosition(Vec3d param);
  //void setLookingAt(Vec3d param);
  void setFieldOfView(double param);
  void setAspectRatio(double param);
  void setNear(double param);
  void setFar(double param);
};

#endif
