#include "Dispatcher.h"
#include "IAction.h"
#include "ITarget.h"

namespace React {

    Dispatcher Dispatcher::ourDispatcher;

    // ----------------------------------------------------------------------
    int timedActionCompare(const List& c1, const List& c2) {
      const ITimedAction& a1 = static_cast<const ITimedAction&>(c1);
      const ITimedAction& a2 = static_cast<const ITimedAction&>(c2);
      return a2.getElapseTime() - a1.getElapseTime();
    }

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
        List* ListToRun = myOnEventQ.pop();
        if(ListToRun != 0) {
            ITarget::endCriticalSection();
            IOnEventAction* toRun = static_cast<IOnEventAction*>(ListToRun);
            toRun->run();
            return;
        }

        // -- 2nd priority: delayed actions. --
        ListToRun = myDelayQ.peek();
        if(ListToRun != 0) {
            IDelayedAction* toRun = static_cast<IDelayedAction*>(ListToRun);
            if(toRun->isReadyToRun()) {
                myDelayQ.pop();
                ITarget::endCriticalSection();
                toRun->run();
                return;
            }
        }

        // -- 3rd priority: periodic actions. --
        ListToRun = myPeriodicQ.peek();
        if(ListToRun != 0) {
            IPeriodicAction* toRun = static_cast<IPeriodicAction*>(ListToRun);
            if(toRun->isReadyToRun()) {
                myPeriodicQ.touch();
                ITarget::endCriticalSection();
                toRun->restartTimerNoDrift();
                toRun->run();
                return;
            }
        }

        // -- 4th priority: background actions. --
        ListToRun = myBackgroundQ.pop();
        if(ListToRun != 0) {
            myBackgroundQ.push(*ListToRun);
            ITarget::endCriticalSection();
            IBackgroundAction* toRun = static_cast<IBackgroundAction*>(ListToRun);
            toRun->run();
            return;
        }
        ITarget::endCriticalSection();
    }

}
