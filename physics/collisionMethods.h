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
  bool bboxOnbbox(BBoxf one,BBoxf two);
  bool bboxOnbbox(BBoxd one,BBoxd two);
  bool sphereOnsphere(Spheref one,Spheref two);
  bool sphereOnsphere(Sphered one,Sphered two);
  bool bboxOnsphere(BBoxf one,Spheref two);
  bool bboxOnsphere(BBoxd one,Sphered two);
};

#endif
