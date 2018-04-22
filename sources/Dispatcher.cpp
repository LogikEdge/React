#include "Dispatcher.h"
#include "IAction.h"
#include "ITarget.h"

namespace LogikEdge { namespace React {

    Dispatcher Dispatcher::ourDispatcher;

    int dummyCompare(Cdll&, Cdll&) { return 0; }

    // ----------------------------------------------------------------------
    /// @param toActivate   The action to be activated.
    void Dispatcher::activate(IOnEventAction& toActivate) {
        ITarget::startCriticalSection();
        myOnEventQ.push(toActivate);
        ITarget::endCriticalSection();
    }
    // ----------------------------------------------------------------------
    /// @param toActivate   The action to be activated.
    void Dispatcher::activate(IDelayedAction& toActivate) {
        toActivate.startTimer();
        ITarget::startCriticalSection();
        myDelayQ.push(toActivate);
        ITarget::endCriticalSection();
    }
    // ----------------------------------------------------------------------
    /// @param toActivate   The action to be activated.
    void Dispatcher::activate(IPeriodicAction& toActivate) {
        toActivate.startTimer();
        ITarget::startCriticalSection();
        myPeriodicQ.push(toActivate);
        ITarget::endCriticalSection();
    }
    // ----------------------------------------------------------------------
    /// @param toActivate   The action to be activated.
    void Dispatcher::activate(IBackgroundAction& toActivate) {
        ITarget::startCriticalSection();
        myBackgroundQ.push(toActivate);
        ITarget::endCriticalSection();
    }

    // ----------------------------------------------------------------------
    /// Runs the next highest priority action that is ready to run.
    void Dispatcher::runOnce() {
        // -- 1st priority: OnEvent actions. --
        ITarget::startCriticalSection();
        Cdll* cdllToRun = myOnEventQ.pop();
        if(cdllToRun != 0) {
            ITarget::endCriticalSection();
            IOnEventAction* toRun = static_cast<IOnEventAction*>(cdllToRun);
            toRun->run();
            return;
        }

        // -- 2nd priority: delayed actions. --
        cdllToRun = myDelayQ.peek();
        if(cdllToRun != 0) {
            IDelayedAction* toRun = static_cast<IDelayedAction*>(cdllToRun);
            if(toRun->isReadyToRun()) {
                myDelayQ.pop();
                ITarget::endCriticalSection();
                toRun->run();
                return;
            }
        }

        // -- 3rd priority: periodic actions. --
        cdllToRun = myPeriodicQ.peek();
        if(cdllToRun != 0) {
            IPeriodicAction* toRun = static_cast<IPeriodicAction*>(cdllToRun);
            if(toRun->isReadyToRun()) {
                myPeriodicQ.touch();
                ITarget::endCriticalSection();
                toRun->restartTimerNoDrift();
                toRun->run();
                return;
            }
        }

        // -- 4th priority: background actions. --
        cdllToRun = myBackgroundQ.pop();
        if(cdllToRun != 0) {
            myBackgroundQ.push(*cdllToRun);
            ITarget::endCriticalSection();
            IBackgroundAction* toRun = static_cast<IBackgroundAction*>(cdllToRun);
            toRun->run();
            return;
        }
        ITarget::endCriticalSection();
    }

}}
