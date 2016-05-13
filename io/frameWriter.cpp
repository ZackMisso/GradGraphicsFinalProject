#include  "frameWriter.h"

FrameWriter* FrameWriter::instance = 0x0;

FrameWriter::FrameWriter() { }

FrameWriter::~FrameWriter() { }

void FrameWriter::writeFramef(PhysicsWorld* ps,string fileName) {
  // to be implemented
}

void FrameWriter::writeFramed(PhysicsWorld* ps,string fileName) {
  // to be implemented
}

void FrameWriter::writePeriSystem(PeriSystemf* peri,ofstream& file) {
  // to be implemented
}

void FrameWriter::writePeriSystem(PeriSystemd* peri,ofstream& file) {
  // to be implemented
}

void FrameWriter::writePhysicsObject(PhysicsObjectf* object,ofstream& file) {
  Vec3f pos = object->getPosition();
  file << pos[0] << " " << pos[1] << " " << pos[2] << " ";
  object->getGeometry()->writeToFile(file);
  file << endl;
}

void FrameWriter::writePhysicsObject(PhysicsObjectd* object,ofstream& file) {
  Vec3d pos = object->getPosition();
  file << pos[0] << " " << pos[1] << " " << pos[2] << " ";
  object->getGeometry()->writeToFile(file);
  file << endl;
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
