#ifndef __TESTVIEW_H__
#define __TESTVIEW_H__

// This view should never be changed and only used to make sure the display is working.
// This view should only display a single triangle on the screen with a black background

#include "view.h"

class TestView : public View {
public:
  virtual void display();
};

#endif
