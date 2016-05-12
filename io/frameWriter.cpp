#include  "frameWriter.h"

FrameWriter* FrameWriter::instance = 0x0;

FrameWriter::FrameWriter() { }

FrameWriter::~FrameWriter() { }

void FrameWriter::writeFramef(PhysicsWorld* ps) {
  // to be implemented
}

void FrameWriter::writeFramed(PhysicsWorld* ps) {
  // to be implemented
}

void FrameWriter::writePeriSystem(PeriSystemf* peri,ofstream& file) {
  // to be implemented
}

void FrameWriter::writePeriSystem(PeriSystemd* peri,ofstream& file) {
  // to be implemented
}

void FrameWriter::writePhysicsObject(PhysicsObjectf* object,ofstream& file) {
  // to be implemented
}

void FrameWriter::writePhysicsObject(PhysicsObjectd* object,ofstream& file) {
  // to be implemented
}

void FrameWriter::writePhysicsBody(PhysicsBodyf* body,ofstream& file) {
  // probably wont be used
}

void FrameWriter::writePhysicsBody(PhysicsBodyd* body,ofstream& file) {
  // probably wont be used
}

FrameWriter* FrameWriter::getInstance() {
  return instance;
}

void FrameWriter::initialize() {
  if(!instance)
    instance = new FrameWriter();
}

void FrameWriter::destroy() {
  if(instance)
    delete instance;
}
