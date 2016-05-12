#ifndef __FRAMEREADER_H__
#define __FRAMEREADER_H__

// reads the contents of a scene for a specified frame

#include "../bake/bakedSystem.h"
#include "../dataStructures/array.h"
#include <iostream>
#include <fstream>

using namespace std;

class FrameReader {
private:
  static FrameReader* instance;
  FrameReader();
  Array<BakedPhysicsObjectf*>* readPeriSystemf(ifstream& file);
  Array<BakedPhysicsObjectd*>* readPeriSystemd(ifstream& file);
  BakedPhysicsObjectf* readPhysicsObjectf(ifstream& file);
  BakedPhysicsObjectd* readPhysicsObjectd(ifstream& file);
  Array<BakedPhysicsObjectf*>* readPhysicsBodyf(ifstream& file);
  Array<BakedPhysicsObjectd*>* readPhysicsBodyd(ifstream& file);
public:
  ~FrameReader();
  void readFramef(BakedSystem* world,string fileName);
  void readFramed(BakedSystem* world,string fileName);
  // singleton methods
  static FrameReader* getInstance();
  static void initialize();
  static void destroy();
};

#endif
