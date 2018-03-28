#ifndef _LogikEdge_Seal_ISeal_h
#define _LogikEdge_Seal_ISeal_h

namespace LogikEdge { namespace Seal {

    struct ISeal {
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
