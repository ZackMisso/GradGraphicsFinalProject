#ifndef __VERTEX_H__
#define __VERTEX_H__

#include "../math/vec3.h"

class Vertexf {
private:
  Vec3f pos;
  Vec3f norm;
public:
  Vertexf(float *vals);
  Vertexf(Vec3f position);
  void addToNorm(Vec3f pos);
  void normalizeNorm();
  // getter methods
  Vec3f getPos();
  Vec3f getNorm();
  // setter methods
  void setPos(Vec3f param);
  void setNorm(Vec3f param);
};

class Vertexd {
private:
  Vec3d pos;
  Vec3d norm;
public:
  Vertexd(float *vals);
  Vertexd(Vec3d positon);
  void addToNorm(Vec3d pos);
  void normalizeNorm();
  // getter methods
  Vec3d getPos();
  Vec3d getNorm();
  // setter methods
  void setPos(Vec3d param);
  void setNorm(Vec3d param);
};

#endif
