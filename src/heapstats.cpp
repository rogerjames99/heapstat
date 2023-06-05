/** \file heapstats.cpp
*/
#include <ArduinoLog.h>
#include <malloc.h>
#include "heapstats.h"

CHeapStats::CHeapStats()
{
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
