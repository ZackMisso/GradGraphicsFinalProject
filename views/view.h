#ifndef __VIEW_H__
#define __VIEW_H__

// this class gets extended for all views

#include "../physics/physicsWorld.h"

class View {
private:
  double timeStep; // always double
  double lengthOfSimulation; // length in seconds
  bool doublePercision;
public:
  View();
  ~View();
  virtual void initialize();
  virtual void deInitialize();
  virtual void keyboard(int key,int scancode,int action,int mods);
  virtual void mouseMove(double x,double y);
  virtual void mouseClick(int button,int action,int mods);
  virtual void display();
  virtual void headless();
  // getter methods
  double getTimeStep();
  double getLengthOfSimulation();
  bool getDoublePercision();
  // setter methods
  void setTimeStep(double param);
  void setLengthOfSimulation(double param);
  void setDoublePercision(bool param);
};

#endif
