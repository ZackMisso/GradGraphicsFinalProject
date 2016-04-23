#ifndef __PERITESTVIEW_H__
#define __PERITESTVIEW_H__

#include "view.h"

class PeriTestView : public View {
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
