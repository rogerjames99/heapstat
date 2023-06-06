/** \file heapstats.h
*/
#ifndef HEAPSTATS_H
#define HEAPSTATS_H

/**
 * @brief Declaration of CHeapStats class.
*/
class CHeapStats
{
protected:
    CHeapStats();

    static bool printHeapStats(void *);
    
    static CHeapStats* singleton;
    
public:
    CHeapStats(CHeapStats &other) = delete;
    void operator=(const CHeapStats &) = delete;
    static CHeapStats *GetInstance();
    void tick(void); 
};
#endif // HEAPSTATS_H


