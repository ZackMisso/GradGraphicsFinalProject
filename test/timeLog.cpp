#include "timeLog.h"

TimeLog::TimeLog(string name) {
  id = name;
  cumulativeTime = 0;
  startTime = 0;
  running = false;
}

void TimeLog::start() {
  if(!running) {
    // startTime = thistime;
    running = true;
  }
}

void TimeLog::stop() {
  if(running) {
    //cumulativeTime += thistime - startTime;
    running = false;
  }
}

void TimeLog::reset() {
  running = false;
  cumulativeTime = 0;
  startTime = 0;
}

bool TimeLog::getRunning() { return running; }
long TimeLog::getCumulativeTime() { return cumulativeTime; }
