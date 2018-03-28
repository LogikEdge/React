#include "Arduino.h"
#include "../ISeal.h"

namespace LogikEdge { namespace Seal {
    // -----------------------------------------------------------------------
    /// Returns a milliseconds timer reference from the Arduino.
    ///
    /// @return The number of milliseconds since startup.
    ///
    long ISeal::getMilliseconds()  { return millis(); }

    // -----------------------------------------------------------------------
    /// Starts a reentrancy barrier.
    void ISeal::startCriticalSection() {}

    // -----------------------------------------------------------------------
    /// Ends previously created reentrancy barrier.
    void ISeal::endCriticalSection()   {}

    // -----------------------------------------------------------------------
    /// Go into low-power mode for the given amount of time.
    ///
    /// @param milliseconds The time period to go to sleep
    ///
    void ISeal::sleep(long milliseconds) {
        delay(milliseconds);
    }
}}
