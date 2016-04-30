#ifndef __TIMELOG_H__
#define __TIMELOG_H__

#include <string>

using namespace std;

class TimeLog {
private:
  string id;
  long cumulativeTime;
  long startTime;
  bool running;
public:
  TimeLog(string name);
  // timing methods
  void start();
  void stop();
  void reset();
  // getter methods
  bool getRunning();
  long getCumulativeTime();
};

#endif
