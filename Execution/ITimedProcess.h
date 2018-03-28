#ifndef _LogikEdge_React_ITimedProcess_h
#define _LogikEdge_React_ITimedProcess_h

#include "IProcess.h"
#include "../System/Timer.h"

namespace LogikEdge { namespace React {
    // ========================================================================
    /// Base of all types that can be queued in the scheduler.
    struct ITimedProcess : public IProcess {

        void startTimer(Milliseconds delay) { myTimer.restart(delay); }
        bool isReadyToRun() const           { return myTimer.isElapsed(); }
        virtual bool isPeriodic() const     { return false; }
        Milliseconds elapsedTime() const    { return myTimer.elapsedTime(); }
        Milliseconds remainingTime() const  { return myTimer.remainingTime(); }

    protected:
        Timer   myTimer;
    };

}}

#endif
