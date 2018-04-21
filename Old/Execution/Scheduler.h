#ifndef _LogikEdge_React_Scheduler_h
#define _LogikEdge_React_Scheduler_h

#include "IProcess.h"
#include "ITimedProcess.h"
#include "IPeriodicProcess.h"
#include "../Containers/List.h"
#include "../Containers/PriorityList.h"

namespace LogikEdge { namespace React {
    struct TimedProcessComparator {
        static int compare(const ITimedProcess& p1, const ITimedProcess& p2) {
            return p2.elapsedTime() - p1.elapsedTime();
        }
    };

    struct Scheduler {

        Scheduler();

        void wakeupEvent(IProcess&);
        void wakeupAfterDelay(ITimedProcess&, Milliseconds);
        void wakeupPeriodic(IPeriodicProcess&, Milliseconds);
        void wakeupContinuous(IProcess&);

        void run();

        Milliseconds    getDelayTillNextTimedProcess(Milliseconds maxDelay);

        static Scheduler&  getInstance()   { return ourInstance; }

    private:
        bool isShutdownRequested() const;

        List<IProcess>                                          myEventQueue;
        PriorityList<ITimedProcess,    TimedProcessComparator>  myTimedQueue;
        List<IProcess>                                          myBackgroundQueue;
        static Scheduler                                        ourInstance;
    };

}}

#endif
