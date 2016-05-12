#ifndef __FRAMEREADER_H__
#define __FRAMEREADER_H__

// reads the contents of a scene for a specified frame

#include "../physics/physicsWorld.h"
#include <iostream>
#include <fstream>

using namespace std;

class FrameReader {
private:
  static FrameReader* instance;
  FrameReader();
  PeriSystemf* readPeriSystemf(ifstream& file);
  PeriSystemd* readPeriSystemd(ifstream& file);
  PhysicsObjectf* readPhysicsObjectf(ifstream& file);
  PhysicsObjectf* readPhysicsObjectd(ifstream& file);
  PhysicsBodyf* readPhysicsBodyf(ifstream& file);
  PhysicsBodyd* readPhysicsBodyd(ifstream& file);
public:
  ~FrameReader();
  void readFramef(PhysicsWorld* world);
  void readFramed(PhysicsWorld* world);
  // singleton methods
  static FrameReader* getInstance();
  static void initialize();
  static void destroy();
};

#endif
