#ifndef SIMULATE
#define SIMULATE
#include "Scheduler.hpp"
#include <chrono>
using namespace std;

double* simulate(Scheduler* sched, int numCPUBound,int numIOBound, int numCycles);

#endif
