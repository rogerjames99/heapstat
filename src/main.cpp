#include <Arduino.h>
#include <ArduinoLog.h>
#include "heapstats.h"

CHeapStats *myheapstats;

void setup()
{
    while(!Serial) delay(100);

    Log.begin(LOG_LEVEL_VERBOSE, &Serial);

    myheapstats = CHeapStats::GetInstance();
}

void loop() {
    myheapstats->tick();
}
