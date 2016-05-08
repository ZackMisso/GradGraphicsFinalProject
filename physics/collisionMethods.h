#ifndef __COLLISIONMETHODS_H__
#define __COLLISIONMETHODS_H__

// a singleton that contains all of the collision detection methods

#include "../geometry/bbox.h"
#include "../geometry/sphere.h"

class CollisionMethods {
private:
  static CollisionMethods* instance;
  CollisionMethods();
public:
  ~CollisionMethods();
  // singleton methods
  static CollisionMethods* getInstance();
  static void initialize();
  static void destroy();
  // collision methods
  bool bboxOnbbox(BBoxf one,BBoxf two,float* pen,Vec3f* norm);
  bool bboxOnbbox(BBoxd one,BBoxd two,double* pen,Vec3d* norm);
  bool sphereOnsphere(Spheref one,Spheref two,float* pen,Vec3f* norm);
  bool sphereOnsphere(Sphered one,Sphered two,double* pen,Vec3d* norm);
  bool bboxOnsphere(BBoxf one,Spheref two,float* pen,Vec3f* norm);
  bool bboxOnsphere(BBoxd one,Sphered two,double* pen,Vec3d* norm);
};

#endif
