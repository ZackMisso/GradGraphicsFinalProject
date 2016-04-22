#ifndef __VIEW_H__
#define __VIEW_H__

// this class gets extended for all views

class View {
private:
public:
  View();
  ~View();
  virtual void initialize();
  virtual void destroy();
  virtual void keyboard(int key,int scancode,int action,int mods);
  virtual void mouseMove(double x,double y);
  virtual void mouseClick(int button,int action,int mods);
  virtual void display();
};

#endif
