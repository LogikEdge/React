#ifndef _LogikEdge_Seal_IPeriodicProcess_h
#define _LogikEdge_Seal_IPeriodicProcess_h

#include "ITimedProcess.h"

namespace LogikEdge { namespace Seal {
    // ========================================================================
    /// Base of all types that can be queued in the scheduler.
    struct IPeriodicProcess : public ITimedProcess {

        void setInterval(Milliseconds theInterval)  { myInterval= theInterval; }
        void startTimer()                           { myTimer.restartNoDrift(myInterval); }
        bool isPeriodic() const                     { return true; }

    private:
        Milliseconds    myInterval;
    };

}}

#endif
