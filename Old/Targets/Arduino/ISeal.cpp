#include "Arduino.h"
#include "../IReact.h"

namespace LogikEdge { namespace React {
    // -----------------------------------------------------------------------
    /// Returns a milliseconds timer reference from the Arduino.
    ///
    /// @return The number of milliseconds since startup.
    ///
    long IReact::getMilliseconds()  { return millis(); }

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
        delay(milliseconds);
    }
}}
