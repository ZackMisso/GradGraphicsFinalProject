#ifndef __COLLISIONTESTVIEW_H__
#define __COLLISIONTESTVIEW_H__

#include "view.h"

class CollisionTestView : public View {
private:
public:
  virtual void initialize();
  virtual void deInitialize();
  virtual void keyboard(int key,int scancode,int action,int mods);
  virtual void mouseMove(double x,double y);
  virtual void mouseClick(int button,int action,int mods);
  virtual void display();
};

#endif
