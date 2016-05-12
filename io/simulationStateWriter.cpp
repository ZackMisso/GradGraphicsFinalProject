#include  "simulationStateWriter.h"

SimulationStateWriter* SimulationStateWriter::instance = 0x0;

SimulationStateWriter::SimulationStateWriter() { }

SimulationStateWriter::~SimulationStateWriter() { }

void SimulationStateWriter::writeSimulationStatef(PhysicsWorld* world,string fileName) {
  // to be implemented
}

void SimulationStateWriter::writeSimulationStated(PhysicsWorld* world,string fileName) {
  // to be implemented
}

void SimulationStateWriter::writePeriSystem(PeriSystemf* peri,ofstream& file) {
  // to be implemented
}

void SimulationStateWriter::writePeriSystem(PeriSystemd* peri,ofstream& file) {
  // to be implemented
}

void SimulationStateWriter::writePhysicsObject(PhysicsObjectf* object,ofstream& file) {
  // to be implemented
}

void SimulationStateWriter::writePhysicsObject(PhysicsObjectd* object,ofstream& file) {
  // to be implemented
}

void SimulationStateWriter::writePhysicsBody(PhysicsBodyf* body,ofstream& file) {
  // probably wont need
}

void SimulationStateWriter::writePhysicsBody(PhysicsBodyd* body,ofstream& file) {
  // probably wont need
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
