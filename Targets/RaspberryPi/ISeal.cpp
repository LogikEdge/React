#include <time.h>
#include <sys/time.h>
#include "../IReact.h"

namespace LogikEdge { namespace React {
    // -----------------------------------------------------------------------
    /// Returns a milliseconds timer reference from the Arduino.
    ///
    /// @return The number of milliseconds since startup.
    ///
    long IReact::getMilliseconds()  {
        struct timeval tv;
        if(gettimeofday(&tv, 0) != 0) return 0;
        return long(tv.tv_sec * 1000L + tv.tv_usec / 1000L);
    }

    // -----------------------------------------------------------------------
    /// Starts a reentrancy barrier.
    void IReact::startCriticalSection() {}

    // -----------------------------------------------------------------------
    /// Ends previously created reentrancy barrier.
    void IReact::endCriticalSection()   {}

    // -----------------------------------------------------------------------
    /// Go into low-power mode for the given amount of time.
    ///
    /// @param milliseconds The time period to go to sleep
    ///
    void IReact::sleep(long milliseconds) {
        struct timespec ts;
        ts.tv_sec= 0;
        if(milliseconds >= 1000L) {
            ts.tv_sec = milliseconds / 1000L;
            milliseconds -= ts.tv_sec * 1000L;
        }
        ts.tv_nsec= milliseconds * 1000L;
        nanosleep(&ts, 0);
    }
}}
