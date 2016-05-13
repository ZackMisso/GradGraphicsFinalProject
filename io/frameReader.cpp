#include  "frameReader.h"

FrameReader* FrameReader::instance = 0x0;

FrameReader::FrameReader() { }

FrameReader::~FrameReader() { }

void FrameReader::readFramef(BakedSystem* world,string fileBase, int frames) {
  Array<BakedPhysicsObjectf*>* objects = new Array<BakedPhysicsObjectf*>();
  ostringstream first;
  first << fileBase << "0.vox";
  ifstream firstFile(first.str());
  string line;

  while (getline(firstFile, line)) {
    if (line.length() > 0) {
      BakedPhysicsObjectf* obj = new BakedPhysicsObjectf();
      // TODO: get initial geometry
      istringstream data(line);
      float trash;
      int geometryType;
      // skip first 3 values and get geometry type
      data >> trash >> trash >> trash;
      data >> geometryType;

      switch (geometryType) {
        case SPHERE: {
          Spheref* sphere = new Spheref();
          float r;
          data >> r;
          sphere->setRadius(r);
          obj->setGeometry(sphere);
          break;
        }

        case CYLINDER: {
          Cylinderf* cylinder = new Cylinderf();
          float r, h;
          data >> r >> h;
          cylinder->setRadius(r);
          cylinder->setHeight(h);
          obj->setGeometry(cylinder);
          break;
        }

        case RECT_PRISM: {
          RectPrismf* rectPrism = new RectPrismf();
          Vec3f d;
          data >> d[0] >> d[1] >> d[2];
          rectPrism->setDimension(d);
          obj->setGeometry(rectPrism);
          break;
        }

        case VOXEL: {
          Voxelf* voxel = new Voxelf();
          float r;
          data >> r;
          voxel->setRadius(r);
          obj->setGeometry(voxel);
          break;
        }

        default: {
          cerr << "geometry type not recognized!" << endl;
          break;
        }
      }

      objects->add(obj);
    }
  }

  for (int frame = 0; frame < frames; ++frame) {
    ostringstream s;
    s << fileBase << frame << ".vox";
    ifstream file(s.str());
    for (int i = 0; i < objects->getSize(); ++i) {
      readPhysicsObjectf(file, objects->get(i));
    }
  }
  world->setObjectsF(objects);
}

void FrameReader::readFramed(BakedSystem* world,string fileBase, int frames) {
  Array<BakedPhysicsObjectd*>* objects = new Array<BakedPhysicsObjectd*>();
  ostringstream first;
  first << fileBase << "0.vox";
  ifstream firstFile(first.str());
  string line;

  while (getline(firstFile, line)) {
    if (line.length() > 0) {
      BakedPhysicsObjectd* obj = new BakedPhysicsObjectd();
      // TODO: get initial geometry
      istringstream data(line);
      double trash;
      int geometryType;
      // skip first 3 values and get geometry type
      data >> trash >> trash >> trash;
      data >> geometryType;

      switch (geometryType) {
        case SPHERE: {
          Sphered* sphere = new Sphered();
          double r;
          data >> r;
          sphere->setRadius(r);
          obj->setGeometry(sphere);
          break;
        }

        case CYLINDER: {
          Cylinderd* cylinder = new Cylinderd();
          double r, h;
          data >> r >> h;
          cylinder->setRadius(r);
          cylinder->setHeight(h);
          obj->setGeometry(cylinder);
          break;
        }

        case RECT_PRISM: {
          RectPrismd* rectPrism = new RectPrismd();
          Vec3d d;
          data >> d[0] >> d[1] >> d[2];
          rectPrism->setDimension(d);
          obj->setGeometry(rectPrism);
          break;
        }

        case VOXEL: {
          Voxeld* voxel = new Voxeld();
          double r;
          data >> r;
          voxel->setRadius(r);
          obj->setGeometry(voxel);
          break;
        }

        default: {
          cerr << "geometry type not recognized!" << endl;
          break;
        }
      }

      objects->add(obj);
    }
  }

  for (int frame = 0; frame < frames; ++frame) {
    ostringstream s;
    s << fileBase << frame << ".vox";
    ifstream file(s.str());
    for (int i = 0; i < objects->getSize(); ++i) {
      readPhysicsObjectd(file, objects->get(i));
    }
  }
  world->setObjectsD(objects);
}

Array<BakedPhysicsObjectf*>* FrameReader::readPeriSystemf(ifstream& file) {
  // to be implemented
  return 0x0;
}

Array<BakedPhysicsObjectd*>* FrameReader::readPeriSystemd(ifstream& file) {
  // to be implemented
  return 0x0;
}

void FrameReader::readPhysicsObjectf(ifstream& file, BakedPhysicsObjectf* o) {
  Vec3f* p = new Vec3f();
  file >> (*p)[0] >> (*p)[1] >> (*p)[2];
  o->getPositions()->add(p);
}

void FrameReader::readPhysicsObjectd(ifstream& file, BakedPhysicsObjectd* o) {
  Vec3d* p = new Vec3d();
  file >> (*p)[0] >> (*p)[1] >> (*p)[2];
  o->getPositions()->add(p);
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
