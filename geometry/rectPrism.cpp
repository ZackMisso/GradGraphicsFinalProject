#include "rectPrism.h"

RectPrismf::RectPrismf() {
  prism = BBoxf();
}

RectPrismf::RectPrismf(Vec3f p,Vec3f d) {
  prism = BBoxf(p,d);
}

RectPrismf::RectPrismf(BBoxf box) {
  prism = box;
}

BBoxf RectPrismf::getBBox() {
  return prism;
}

bool RectPrismf::containsPoint(Vec3f point) {
  // to be implemented
  return false;
}

void RectPrismf::writeToFile(ofstream& file) {
  // to be implemented
}

void RectPrismf::readFromFile(ifstream& file) {
  // to be implemented
}

BBoxf RectPrismf::getPrism() { return prism; }

void RectPrismf::setPrism(BBoxf param) { prism = param; }

//////////////////// DOUBLE VERSION ///////////////////////

RectPrismd::RectPrismd() {
  prism = BBoxd();
}

RectPrismd::RectPrismd(Vec3d p,Vec3d d) {
  prism = BBoxd(p,d);
}

RectPrismd::RectPrismd(BBoxd box) {
  prism = box;
}

BBoxd RectPrismd::getBBox() {
  return prism;
}

bool RectPrismd::containsPoint(Vec3d point) {
  // to be implemented
  return false;
}

void RectPrismd::writeToFile(ofstream& file) {
  // to be implemented
}

void RectPrismd::readFromFile(ifstream& file) {
  // to be implemented
}

BBoxd RectPrismd::getPrism() { return prism; }

void RectPrismd::setPrism(BBoxd param) { prism = param; }
