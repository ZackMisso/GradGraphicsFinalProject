#ifndef __FRAMEWRITER_H__
#define __FRAMEWRITER_H__

// writes the contents of a scene for a specified frame

#include "../physics/physicsWorld.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FrameWriter {
private:
  static FrameWriter* instance;
  FrameWriter();
public:
  void writePeriSystem(PeriSystemf* peri,ofstream& file);
  void writePeriSystem(PeriSystemd* peri,ofstream& file);
  void writePhysicsObject(PhysicsObjectf* object,ofstream& file);
  void writePhysicsObject(PhysicsObjectd* object,ofstream& file);
  void writePhysicsBody(PhysicsBodyf* body,ofstream& file);
  void writePhysicsBody(PhysicsBodyd* body,ofstream& file);
  ~FrameWriter();
  void writeFramef(PhysicsWorld* world,string fileName);
  void writeFramed(PhysicsWorld* world,string fileName);
  // singleton methods
  static FrameWriter* getInstance();
  static void initialize();
  static void destroy();
};

#endif
