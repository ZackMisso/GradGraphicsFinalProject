#ifndef __PHYSICSENGINE_H__
#define __PHYSICSENGINE_H__

// A singleton that oversees all physics interactions

class PhysicsEngine {
private:
  static PhysicsEngine* instance;
  PhysicsEngine();
public:
  ~PhysicsEngine();
  // singleton methods
  static PhysicsEngine* getInstance();
  static void initialize();
  static void destroy();
};

#endif
