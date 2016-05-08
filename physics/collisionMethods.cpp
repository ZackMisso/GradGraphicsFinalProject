#include "collisionMethods.h"

CollisionMethods* CollisionMethods::instance = 0x0;

CollisionMethods::CollisionMethods() {
  // does nothing for now
}

CollisionMethods::~CollisionMethods() {
  // does nothing for now
}

CollisionMethods* CollisionMethods::getInstance() {
  return instance;
}

void CollisionMethods::initialize() {
  if(!instance)
    instance = new CollisionMethods();
}

void CollisionMethods::destroy() {
  if(instance)
    delete instance;
}

bool CollisionMethods::bboxOnbbox(BBoxf one,BBoxf two,float* pen,Vec3f* norm) {
  if(one.getPosition()[0] > two.getPosition()[0] + two.getDimension()[0])
    return false;
  if(one.getPosition()[1] > two.getPosition()[1] + two.getDimension()[1])
    return false;
  if(one.getPosition()[2] > two.getPosition()[2] + two.getDimension()[2])
    return false;
  if(one.getPosition()[0] + one.getDimension()[0] < two.getPosition()[0])
    return false;
  if(one.getPosition()[1] + one.getDimension()[1] < two.getPosition()[1])
    return false;
  if(one.getPosition()[2] + one.getDimension()[2] < two.getPosition()[2])
    return false;
  // ToDo :: Calculate the penetration and normal
  return true;
}

bool CollisionMethods::bboxOnbbox(BBoxd one,BBoxd two,double* pen,Vec3d* norm) {
  if(one.getPosition()[0] > two.getPosition()[0] + two.getDimension()[0])
    return false;
  if(one.getPosition()[1] > two.getPosition()[1] + two.getDimension()[1])
    return false;
  if(one.getPosition()[2] > two.getPosition()[2] + two.getDimension()[2])
    return false;
  if(one.getPosition()[0] + one.getDimension()[0] < two.getPosition()[0])
    return false;
  if(one.getPosition()[1] + one.getDimension()[1] < two.getPosition()[1])
    return false;
  if(one.getPosition()[2] + one.getDimension()[2] < two.getPosition()[2])
    return false;
  // ToDo :: Calculate the penetration and normal
  return true;
}

bool CollisionMethods::sphereOnsphere(Spheref one,Spheref two,float* pen,Vec3f* norm) {
  Vec3f dif = one.getPosition() - two.getPosition();
  float dist = dif.mag();
  // ToDo :: Calculate the penetration and normal
  return dist < one.getRadius() + two.getRadius();
}

bool CollisionMethods::sphereOnsphere(Sphered one,Sphered two,double* pen,Vec3d* norm) {
  Vec3d dif = one.getPosition() - two.getPosition();
  double dist = dif.mag();
  // ToDo :: Calculate the penetration and normal
  return dist < one.getRadius() + two.getRadius();
}

bool CollisionMethods::bboxOnsphere(BBoxf one,Spheref two,float* pen,Vec3f* norm) {
  float dmin = 0.0f;

  Vec3f center = two.getPosition();
  Vec3f bmin = one.getPosition();
  Vec3f bmax = one.getPosition() + one.getDimension();

  if(center[0] < bmin[0])
    dmin += (center[0]-bmin[0]) * (center[0]-bmin[0]);
  else if(center[0] > bmax[0])
    dmin += (center[0]-bmax[0]) * (center[0]-bmax[0]);

  if(center[1] < bmin[1])
    dmin += (center[1]-bmin[1]) * (center[1]-bmin[1]);
  else if(center[1] > bmax[1])
    dmin += (center[1]-bmax[1]) * (center[1]-bmax[1]);

  if(center[2] < bmin[2])
    dmin += (center[2]-bmin[2]) * (center[2]-bmin[2]);
  else if(center[2] > bmax[2])
    dmin += (center[2]-bmax[2]) * (center[2]-bmax[2]);
  // ToDo :: Calculate the penetration and normal
  return dmin <= two.getRadius() * two.getRadius();
}

bool CollisionMethods::bboxOnsphere(BBoxd one,Sphered two,double* pen,Vec3d* norm) {
  double dmin = 0.0f;

  Vec3d center = two.getPosition();
  Vec3d bmin = one.getPosition();
  Vec3d bmax = one.getPosition() + one.getDimension();

  if(center[0] < bmin[0])
    dmin += (center[0]-bmin[0]) * (center[0]-bmin[0]);
  else if(center[0] > bmax[0])
    dmin += (center[0]-bmax[0]) * (center[0]-bmax[0]);

  if(center[1] < bmin[1])
    dmin += (center[1]-bmin[1]) * (center[1]-bmin[1]);
  else if(center[1] > bmax[1])
    dmin += (center[1]-bmax[1]) * (center[1]-bmax[1]);

  if(center[2] < bmin[2])
    dmin += (center[2]-bmin[2]) * (center[2]-bmin[2]);
  else if(center[2] > bmax[2])
    dmin += (center[2]-bmax[2]) * (center[2]-bmax[2]);
  // ToDo :: Calculate the penetration and normal
  return dmin <= two.getRadius() * two.getRadius();
}
