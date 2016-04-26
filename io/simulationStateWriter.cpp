#include  "simulationStateWriter.h"

SimulationStateWriter* SimulationStateWriter::instance = 0x0;

SimulationStateWriter::SimulationStateWriter() { }

SimulationStateWriter::~SimulationStateWriter() { }

void writeSimulationStatef(PeriSystemf* ps) {
  // to be implemented
}

void writeSimulationStated(PeriSystemd* ps) {
  // to be implemented
}

SimulationStateWriter* SimulationStateWriter::getInstance() {
  return instance;
}

void SimulationStateWriter::initialize() {
  if(!instance)
    instance = new SimulationStateWriter();
}

void SimulationStateWriter::destroy() {
  if(instance)
    delete instance;
}
