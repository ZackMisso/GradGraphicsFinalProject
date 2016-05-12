#include "view.h"

View::View() {
  lengthOfSimulation = 4.0;
  timeStep = 1.0/60.0;
  doublePercision = false;
}

View::~View() { }

void View::initialize() { }

void View::deInitialize() { }

void View::keyboard(int key,int scancode,int action,int mods) { }

void View::mouseMove(double x,double y) { }

void View::mouseClick(int button,int action,int mods) { }

void View::display() { }

void View::headless() { }

void View::headlessFromFrame(int frame) { }

double View::getTimeStep() { return timeStep; }
double View::getLengthOfSimulation() { return lengthOfSimulation; }
bool View::getDoublePercision() { return doublePercision; }

void View::setTimeStep(double param) { timeStep = param; }
void View::setLengthOfSimulation(double param) { lengthOfSimulation = param; }
void View::setDoublePercision(bool param) { doublePercision = param; }
