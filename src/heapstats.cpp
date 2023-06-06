/** \file heapstats.cpp
*/
#include <ArduinoLog.h>
#include <arduino-timer.h>
#include <malloc.h>
#include "heapstats.h"

static Timer<1> timer; // Cannot have a template as a class member

CHeapStats::CHeapStats()
{
    ::timer.every(10000, CHeapStats::printHeapStats);
}

void CHeapStats::tick(void)
{
  ::timer.tick();
}

CHeapStats* CHeapStats::singleton = nullptr;

CHeapStats *CHeapStats::GetInstance()
{
    if(singleton == nullptr){
        singleton = new CHeapStats();
    }
    return singleton;
}

bool CHeapStats::printHeapStats(void *)
{
  Log.verbose("======================================\n");
  Log.verbose("                arena: %d\n", mallinfo().arena);
  Log.verbose("total allocated space: %d\n", mallinfo().uordblks);
  Log.verbose("total non-inuse space: %d\n", mallinfo().fordblks);
  Log.verbose(" top releasable space: %d\n", mallinfo().keepcost);
  Log.verbose("======================================\n");
  return true;
}
