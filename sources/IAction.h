#ifndef LogikEdge_React_IAction_h
#define LogikEdge_React_IAction_h

#include "Cdll.h"
#include "Dispatcher.h"
#include "Timer.h"

namespace LogikEdge { namespace React {

    // =======================================================================
    struct IAction : private Cdll {

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

        bool isReadyToRun() const   { return myTimer.isElapsed(); }
        void startTimer()           { myTimer.start(myDelay); }
        void restartTimerNoDrift()  { myTimer.restartNoDrift(myDelay); }
        void stopTimer()            { myTimer.stop(); }

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

}}
#endif
