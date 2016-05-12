#include  "frameReader.h"

FrameReader* FrameReader::instance = 0x0;

FrameReader::FrameReader() { }

FrameReader::~FrameReader() { }

void FrameReader::readFramef(BakedSystem* world,string fileName) {
  // to be implemented
}

void FrameReader::readFramed(BakedSystem* world,string fileName) {
  // to be implemented
}

Array<BakedPhysicsObjectf*>* FrameReader::readPeriSystemf(ifstream& file) {
  // to be implemented
  return 0x0;
}

Array<BakedPhysicsObjectd*>* FrameReader::readPeriSystemd(ifstream& file) {
  // to be implemented
  return 0x0;
}

BakedPhysicsObjectf* FrameReader::readPhysicsObjectf(ifstream& file) {
  // to be implemented
  return 0x0;
}

BakedPhysicsObjectd* FrameReader::readPhysicsObjectd(ifstream& file) {
  // to be implemented
  return 0x0;
}

Array<BakedPhysicsObjectf*>* FrameReader::readPhysicsBodyf(ifstream& file) {
  // to be implemented
  return 0x0;
}

Array<BakedPhysicsObjectd*>* FrameReader::readPhysicsBodyd(ifstream& file) {
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
