#ifndef __FRAME_H__
#define __FRAME_H__

// this class contains the baked scene data for a frame

#include "../dataStructures/array.h"
#include "../peri/bakePointMass.h"
#include "../geometry/tri.h"
#include "camera.h"
#include "renderInclude.h"

class Framef {
private:
  Array<BakePointMassf*>* pointMasses;
  Array<Trif*>* otherTris;
  Cameraf* camera;
public:
  Framef();
  ~Framef();
  void display();
  // getter methods
  Array<BakePointMassf*>* getPointMasses();
  Array<Trif*>* getOtherTris();
  Cameraf* getCamera();
  // setter methods
  void setPointMasses(Array<BakePointMassf*>* param);
  void setOtherTris(Array<Trif*>* param);
  void setCamera(Cameraf* param);
};

class Framed {
private:
  Array<BakePointMassd*>* pointMasses;
  Array<Trid*>* otherTris;
  Camerad* camera;
public:
  Framed();
  ~Framed();
  void display();
  // getter methods
  Array<BakePointMassd*>* getPointMasses();
  Array<Trid*>* getOtherTris();
  Camerad* getCamera();
  // setter methods
  void setPointMasses(Array<BakePointMassd*>* param);
  void setOtherTris(Array<Trid*>* param);
  void setCamera(Camerad* param);
};

#endif
