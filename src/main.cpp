#include <Arduino.h>
#include <ArduinoLog.h>
#include "heapstats.h"

void setup()
{
    while(!Serial) delay(100);

    Log.begin(LOG_LEVEL_VERBOSE, &Serial);

}

void loop()
{
    CHeapStats::GetInstance()->tick();
}
