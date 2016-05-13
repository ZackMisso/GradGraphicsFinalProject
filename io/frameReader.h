#ifndef __FRAMEREADER_H__
#define __FRAMEREADER_H__

// reads the contents of a scene for a specified frame

#include "../bake/bakedSystem.h"
#include "../dataStructures/array.h"
#include "../geometry/geometry.h"
#include "../geometry/sphere.h"
#include "../geometry/cylinder.h"
#include "../geometry/rectPrism.h"
#include "../geometry/voxel.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class FrameReader {
private:
  static FrameReader* instance;
  FrameReader();
  Array<BakedPhysicsObjectf*>* readPeriSystemf(ifstream& file);
  Array<BakedPhysicsObjectd*>* readPeriSystemd(ifstream& file);
  void readPhysicsObjectf(ifstream& file, BakedPhysicsObjectf* o);
  void readPhysicsObjectd(ifstream& file, BakedPhysicsObjectd* o);
  Array<BakedPhysicsObjectf*>* readPhysicsBodyf(ifstream& file);
  Array<BakedPhysicsObjectd*>* readPhysicsBodyd(ifstream& file);
public:
  ~FrameReader();
  void readFramef(BakedSystem* world,string fileBase, int frames);
  void readFramed(BakedSystem* world,string fileBase, int frames);
  // singleton methods
  static FrameReader* getInstance();
  static void initialize();
  static void destroy();
};

#endif
