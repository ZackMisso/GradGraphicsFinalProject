#include "viewController.h"
#include "testView.h"
#include "periTestView.h"
#include "voxelizeView.h"
#include "trimeshIOView.h"
#include "frameIOView.h"
#include "replayView.h"
#include "collisionTestView.h"
#include "finalDemoView.h"
#include "springTestView.h"
#include "physicsEngineTestView.h"
#include "periTestViewDouble.h"
#include "springTestViewDouble.h"
#include "collisionTestDoubleView.h"
#include "fractureView.h"
#include "fractureOne.h"
#include "fractureTwo.h"
#include "fractureThree.h"
#include "fractureFour.h"
#include "fractureFive.h"
#include "fractureThree3D.h"
#include "fractureFail.h"
#include "awesomeFail.h"

ViewController* ViewController::instance = 0x0;

ViewController::ViewController(ViewID id) {
  views = new Array<View*>();
  currentView = 0x0;
  createViews();
  switchToView(id);
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
  views->add(new TrimeshIOView());
  views->add(new FrameIOView());
  views->add(new ReplayView());
  views->add(new CollisionTestView());
  views->add(new FinalDemoView());
  views->add(new SpringTestView());
  views->add(new PhysicsEngineTestView());
  views->add(new PeriTestViewDouble());
  views->add(new SpringTestViewDouble());
  views->add(new CollisionTestDoubleView());
  views->add(new FractureView());
  views->add(new FractureOne());
  views->add(new FractureTwo());
  views->add(new FractureThree());
  views->add(new FractureFour());
  views->add(new FractureFive());
  views->add(new FractureThree3D());
  views->add(new FractureFail());
  views->add(new AwesomeFail());
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

void ViewController::initialize(ViewID id) {
  if(!instance)
    instance = new ViewController(id);
}

void ViewController::destroy() {
  if(instance) {
    delete instance;
    instance = 0x0;
  }
}

View* ViewController::getCurrentView() { return currentView; }
