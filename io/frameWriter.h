#ifndef __FRAMEWRITER_H__
#define __FRAMEWRITER_H__

// writes the contents of a scene for a specified frame

#include "../physics/physicsWorld.h"
#include <iostream>
#include <fstream>

using namespace std;

class FrameWriter {
private:
  static FrameWriter* instance;
  FrameWriter();
  void writePeriSystem(PeriSystemf* peri,ofstream& file);
  void writePeriSystem(PeriSystemd* peri,ofstream& file);
  void writePhysicsObject(PhysicsObjectf* object,ofstream& file);
  void writePhysicsObject(PhysicsObjectd* object,ofstream& file);
  void writePhysicsBody(PhysicsBodyf* body,ofstream& file);
  void writePhysicsBody(PhysicsBodyd* body,ofstream& file);
public:
  ~FrameWriter();
  void writeFramef(PhysicsWorld* world);
  void writeFramed(PhysicsWorld* world);
  // singleton methods
  static FrameWriter* getInstance();
  static void initialize();
  static void destroy();
};

#endif
