#ifndef __FINALDEMOVIEW_H__
#define __FINALDEMOVIEW_H__

// This View Will be used to run our final Simulation

#include "view.h"

class FinalDemoView : public View {
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
