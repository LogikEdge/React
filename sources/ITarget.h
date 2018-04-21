#ifndef LogikEdge_React_ITarget_h
#define LogikEdge_React_ITarget_h

namespace LogikEdge { namespace React {

    namespace ITarget {
        // -----------------------------------------------------------------------
        /// Returns a milliseconds timer reference.
        ///
        /// @return The number of milliseconds since startup.
        ///
        extern long getMilliseconds();

        // -----------------------------------------------------------------------
        /// Starts a reentrancy barrier.
        extern void startCriticalSection();

        // -----------------------------------------------------------------------
        /// Ends previously created reentrancy barrier.
        extern void endCriticalSection();

        // -----------------------------------------------------------------------
        /// Go into low-power mode for the given amount of time.
        ///
        /// @param milliseconds The time period to go to sleep
        ///
        extern void sleep(long milliseconds);
    }

}}

#endif
