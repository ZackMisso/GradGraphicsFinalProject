#ifndef __VOXELIZEVIEW_H__
#define __VOXELIZEVIEW_H__

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include "view.h"
#include "../geometry/bbox.h"
#include "../geometry/voxel.h"
#include "../dataStructures/array.h"

class VoxelizeView : public View {
private:
  Array<Voxelf*>* voxelMesh;
  BBoxf originalShape;
  float voxelRad;
  float dt; // used for animating
  bool displayOriginalShape;
  bool displayVoxels;
  bool animateDisplay;
  bool wireframe;
public:
  virtual void initialize();
  virtual void deInitialize();
  virtual void keyboard(int key,int scancode,int action,int mods);
  virtual void mouseMove(double x,double y);
  virtual void mouseClick(int button,int action,int mods);
  virtual void display();
};

#endif
