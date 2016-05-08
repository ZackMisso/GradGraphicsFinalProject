#ifndef __COLLISIONOBJECT_H__
#define __COLLISIONOBJECT_H__

class CollisionObject {
private:
  void* object;
  bool isPhysicsObject;
  bool isPhysicsBody;
  bool isPeriSystem;
public:
  CollisionObject();
  CollisionObject(void* param,bool obj,bool body,bool peri);
  ~CollisionObject();
  void falsifyAll();
  // getter methods
  void* getObject();
  bool getIsPhysicsObject();
  bool getIsPhysicsBody();
  bool getIsPeriSystem();
  // setter methods
  void setObject(void* param);
  void setIsPhysicsObject(bool param);
  void setIsPhysicsBody(bool param);
  void setIsPeriSystem(bool param);
};

#endif
