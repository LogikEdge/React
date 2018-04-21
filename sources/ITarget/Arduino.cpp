#include "Arduino.h"

namespace LogikEdge { namespace React {

    namespace ITarget {
        // -----------------------------------------------------------------------
        /// Returns a milliseconds timer reference from the Arduino.
        ///
        /// @return The number of milliseconds since startup.
        ///
        long getMilliseconds()  { return millis(); }

        // -----------------------------------------------------------------------
        /// Starts a reentrancy barrier.
        void startCriticalSection() {}

        // -----------------------------------------------------------------------
        /// Ends previously created reentrancy barrier.
        void endCriticalSection()   {}

        // -----------------------------------------------------------------------
        /// Go into low-power mode for the given amount of time.
        ///
        /// @param milliseconds The time period to go to sleep
        ///
        void sleep(long milliseconds) {
            delay(milliseconds);
        }
    }

}}
