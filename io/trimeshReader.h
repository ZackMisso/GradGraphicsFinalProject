#ifndef __TRIMESHREADER_H__
#define __TRIMESHREADER_H__

// reads the contents of a scene for a specified frame

#include "../geometry/trimesh.h"

class TriMeshReader {
private:
  static TriMeshReader* instance;
  TriMeshReader();
public:
  ~TriMeshReader();
  void readTriMeshf(TriMeshf* tm);
  void readTriMeshf(TriMeshd* tm);
  // singleton methods
  static TriMeshReader* getInstance();
  static void initialize();
  static void destroy();
};

#endif
