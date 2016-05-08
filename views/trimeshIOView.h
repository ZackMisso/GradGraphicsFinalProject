#ifndef __TRIMESHIOVIEW_H__
#define __TRIMESHIOVIEW_H__

#include "../geometry/trimesh.h"
#include "view.h"

class TrimeshIOView : public View {
private:
  TriMeshf* trimesh;
public:
  virtual void initialize();
  virtual void deInitialize();
  virtual void display();
};

#endif
