#include "viewController.h"
#include "testView.h"
#include "periTestView.h"
#include "voxelizeView.h"

ViewController* ViewController::instance = 0x0;

ViewController::ViewController() {
  views = new Array<View*>();
  currentView = 0x0;
  createViews();
  switchToView(TEST_VIEW);
}

ViewController::~ViewController() {
  currentView = 0x0;
  while(views->getSize())
    delete views->removeLast();
  delete views;
}

void ViewController::createViews() {
  views->add(new TestView());
  views->add(new PeriTestView());
  views->add(new VoxelizeView());
  // create more in the order they appear in the enum
}

void ViewController::switchToView(ViewID id) {
  if(currentView)
    currentView->deInitialize();
  currentView = views->get(id);
  currentView->initialize();
}

ViewController* ViewController::getInstance() {
  return instance;
}

void ViewController::initialize() {
  if(!instance)
    instance = new ViewController();
}

void ViewController::destroy() {
  if(instance)
    delete instance;
}

View* ViewController::getCurrentView() { return currentView; }
