#include  "frameReader.h"

FrameReader* FrameReader::instance = 0x0;

FrameReader::FrameReader() { }

FrameReader::~FrameReader() { }

void FrameReader::readFramef(PhysicsWorld* ps) {
  // to be implemented
}

void FrameReader::readFramed(PhysicsWorld* ps) {
  // to be implemented
}

PeriSystemf* FrameReader::readPeriSystemf(ifstream& file) {
  // to be implemented
  return 0x0;
}

PeriSystemd* FrameReader::readPeriSystemd(ifstream& file) {
  // to be implemented
  return 0x0;
}

PhysicsObjectf* FrameReader::readPhysicsObjectf(ifstream& file) {
  // to be implemented
  return 0x0;
}

PhysicsObjectf* FrameReader::readPhysicsObjectd(ifstream& file) {
  // to be implemented
  return 0x0;
}

PhysicsBodyf* FrameReader::readPhysicsBodyf(ifstream& file) {
  // to be implemented
  return 0x0;
}

PhysicsBodyd* FrameReader::readPhysicsBodyd(ifstream& file) {
  // to be implemented
  return 0x0;
}

FrameReader* FrameReader::getInstance() {
  return instance;
}

void FrameReader::initialize() {
  if(!instance)
    instance = new FrameReader();
}

void FrameReader::destroy() {
  if(instance)
    delete instance;
}
