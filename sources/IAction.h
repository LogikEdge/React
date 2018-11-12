#ifndef LogikEdge_React_IAction_h
#define LogikEdge_React_IAction_h

#include "Cdll.h"
#include "Dispatcher.h"
#include "Timer.h"

namespace LogikEdge { namespace React {

    // =======================================================================
    struct IAction : public Cdll {

        virtual void activate() { run(); }
        bool isActive() const   { return !isIsolated(); }


        // ------------------------------------------------------------------
        /// The specialization of the Action.
        virtual void run()= 0;

        friend struct Dispatcher;
    };

    struct IOnEventAction : public IAction {
        void activate() { Dispatcher::getInstance().activate(*this); }
    };

    struct IBackgroundAction : public IAction {
        void activate() { Dispatcher::getInstance().activate(*this); }
    };

    struct ITimedAction : public IAction {
        ITimedAction(Milliseconds theDelay) {
            myDelay = theDelay;
        }

        bool         isReadyToRun() const   { return myTimer.isElapsed(); }
        void         startTimer()           { myTimer.start(myDelay); }
        void         restartTimerNoDrift()  { myTimer.restartNoDrift(myDelay); }
        void         stopTimer()            { myTimer.stop(); }
        Milliseconds getElapseTime() const  { return myTimer.getElapseTime(); }

    protected:
        Timer           myTimer;    //< Timer used for periodic and delayed execution.
        Milliseconds    myDelay;    //< Timer delay value
    };

    struct IPeriodicAction : public ITimedAction {
        IPeriodicAction(Milliseconds thePeriod) : ITimedAction(thePeriod) {}

        void activate() { Dispatcher::getInstance().activate(*this); }
    };

    struct IDelayedAction : public ITimedAction {
        IDelayedAction(Milliseconds thePeriod) : ITimedAction(thePeriod) {}

        void activate() { Dispatcher::getInstance().activate(*this); }
    };

    // ======================================================================
    /// The TimedProcessComparator should be used to determine which
    /// time dependent process is the next to elapse.
    ///
    /// NOTE: This comparator is used by the scheduler to order the
    ///       execution of the time dependent processes.
    struct TimedProcessComparator {
        static int compare(const ITimedAction& p1, const ITimedAction& p2) {
            return (int)(p2.getElapseTime() - p1.getElapseTime());
        }
    };
}}
#endif
