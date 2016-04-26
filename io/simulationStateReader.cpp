#include  "simulationStateReader.h"

SimulationStateReader* SimulationStateReader::instance = 0x0;

SimulationStateReader::SimulationStateReader() { }

SimulationStateReader::~SimulationStateReader() { }

void readSimulationStatef(PeriSystemf* ps) {
  // to be implemented
}

void readSimulationStated(PeriSystemd* ps) {
  // to be implemented
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
