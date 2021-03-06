#ifndef __MODELER_H__
#define __MODELER_H__

// This is a singleton that can be used to draw 3D primitives

#include "renderInclude.h"
#include "../math/vec3.h"
#include "../geometry/bbox.h"

class Modeler {
private:
  static Modeler* instance;
  Modeler();
public:
  ~Modeler();
  // singleton methods
  static Modeler* getInstance();
  static void initialize();
  static void destroy();
  // methods
  void drawCube(RenderMode rm);
  void drawCube(RenderMode rm,Vec3f pos,float dim);
  void drawCube(RenderMode rm,Vec3d pos,double dim);
  void drawBBox(RenderMode rm,BBoxf box);
  void drawBBox(RenderMode rm,BBoxd box);
  // TODO :: Add methods for spheres
  // TODO :: Add methods for cylinders
};

#endif
