#include  "simulationStateReader.h"

SimulationStateReader* SimulationStateReader::instance = 0x0;

SimulationStateReader::SimulationStateReader() { }

SimulationStateReader::~SimulationStateReader() { }

void SimulationStateReader::readSimulationStatef(PhysicsWorld* ps) {
  // to be implemented
}

void SimulationStateReader::readSimulationStated(PhysicsWorld* ps) {
  // to be implemented
}

PeriSystemf* SimulationStateReader::readPeriSystemf(ifstream& file) {
  // to be implemented
  return 0x0;
}

PeriSystemd* SimulationStateReader::readPeriSystemd(ifstream& file) {
  // to be implemented
  return 0x0;
}

PhysicsObjectf* SimulationStateReader::readPhysicsObjectf(ifstream& file) {
  // to be implemented
  return 0x0;
}

PhysicsObjectf* SimulationStateReader::readPhysicsObjectd(ifstream& file) {
  // to be implemented
  return 0x0;
}

PhysicsBodyf* SimulationStateReader::readPhysicsBodyf(ifstream& file) {
  // probably wont be needed
  return 0x0;
}

PhysicsBodyd* SimulationStateReader::readPhysicsBodyd(ifstream& file) {
  // probably wont be needed
  return 0x0;
}

SimulationStateReader* SimulationStateReader::getInstance() {
  return instance;
}

void SimulationStateReader::initialize() {
  if(!instance)
    instance = new SimulationStateReader();
}

void SimulationStateReader::destroy() {
  if(instance)
    delete instance;
}
