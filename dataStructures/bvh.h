#ifndef __BVH_H__
#define __BVH_H__

#include "array.h"
#include "../geometry/geometry.h"

class BVHfNode {
private:
  BVHfNode* right;
  BVHfNode* left;
  Array<Geometryf*>* contents;
public:
  BVHfNode();
  ~BVHfNode();
  // getter methods
  BVHfNode* getRight();
  BVHfNode* getLeft();
  Array<Geometryf*>* getContents();
  // setter methods
  void setRight(BVHfNode* param);
  void setLeft(BVHfNode* param);
  void setGeometry(Array<Geometryf*>* param);
};

class BVHf {
private:
  BVHfNode* root;
public:
  BVHf();
  ~BVHf();
  // getter methods
  BVHfNode* getRoot();
  // setter methods
  void setRoot(BVHfNode* param);
};

class BVHdNode {
private:
  BVHdNode* right;
  BVHdNode* left;
  Array<Geometryd*>* contents;
public:
  BVHdNode();
  ~BVHdNode();
  // getter methods
  BVHdNode* getRight();
  BVHdNode* getLeft();
  Array<Geometryd*>* getContents();
  // setter methods
  void setRight(BVHdNode* param);
  void setLeft(BVHdNode* param);
  void setGeometry(Array<Geometryd*>* param);
};

class BVHd {
private:
  BVHdNode* root;
public:
  BVHd();
  ~BVHd();
  // getter methods
  BVHdNode* getRoot();
  // setter methods
  void setRoot(BVHdNode* param);
};

#endif
