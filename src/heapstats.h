/** \file heapstats.h
*/
#ifndef HEAPSTATS_H
#define HEAPSTATS_H

#include <arduino-timer.h>

/**
 * @brief Declaration of CHeapStats class.
*/
class CHeapStats
{
protected:
    CHeapStats();

    static bool printHeapStats(void *);
    
    static CHeapStats* singleton;
    
    Timer<1> timer1; //This version gives a compiler warning.

    static Timer<1> timer; // Force the storage class to static - this supresses the
                            // compiler warning but still leaves the symbol undefined


public:
    CHeapStats(CHeapStats &other) = delete;
    void operator=(const CHeapStats &) = delete;
    static CHeapStats *GetInstance();
    void tick(void) { timer.tick(); }
};
#endif // HEAPSTATS_H


