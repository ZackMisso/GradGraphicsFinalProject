#include  "trimeshReader.h"

TriMeshReader* TriMeshReader::instance = 0x0;

TriMeshReader::TriMeshReader() { }

TriMeshReader::~TriMeshReader() { }

void TriMeshReader::readTriMeshf(TriMeshf* tm) {
  // to be implemented
}

void TriMeshReader::readTriMeshf(TriMeshd* tm) {
  // to be implemented
}

TriMeshReader* TriMeshReader::getInstance() {
  return instance;
}

void TriMeshReader::initialize() {
  if(!instance)
    instance = new TriMeshReader();
}

void TriMeshReader::destroy() {
  if(instance)
    delete instance;
}
