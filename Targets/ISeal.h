#ifndef _LogikEdge_React_IReact_h
#define _LogikEdge_React_IReact_h

namespace LogikEdge { namespace React {

    struct IReact {
        /// Returns a milliseconds reference time base.
        static long getMilliseconds();
        /// Creates a reentrancy barrier.
        static void startCriticalSection();
        /// Remove the previously created reentrancy barrier.
        static void endCriticalSection();
        /// Go into low-power mode for the given period.
        static void sleep(long milliseconds);
    };

}}

#endif
