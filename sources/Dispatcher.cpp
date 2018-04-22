#include "Dispatcher.h"
#include "IAction.h"

namespace LogikEdge { namespace React {

    Dispatcher Dispatcher::ourDispatcher;

    int dummyCompare(Cdll&, Cdll&) { return 0; }

    void Dispatcher::activate(IOnEventAction& toActivate) {
        myOnEventQ.push(toActivate);
    }
    void Dispatcher::activate(IDelayedAction& toActivate) {
        toActivate.startTimer();
        myDelayQ.push(toActivate);
    }
    void Dispatcher::activate(IPeriodicAction& toActivate) {
        toActivate.startTimer();
        myPeriodicQ.push(toActivate);
    }
    void Dispatcher::activate(IBackgroundAction& toActivate) {
        myBackgroundQ.push(toActivate);
    }

    void Dispatcher::runOnce() {
        // -- First empty the OnEvent queue. --
        Cdll* cdllToRun = myOnEventQ.pop();
        if(cdllToRun != 0) {
            IOnEventAction* toRun = static_cast<IOnEventAction*>(cdllToRun);
            toRun->run();
            return;
        }

        cdllToRun = myDelayQ.peek();
        if(cdllToRun != 0) {
            IDelayedAction* toRun = static_cast<IDelayedAction*>(cdllToRun);
            if(toRun->isReadyToRun()) {
                myDelayQ.pop();
                toRun->run();
            }
        }

        cdllToRun = myPeriodicQ.peek();
        if(cdllToRun != 0) {
            IPeriodicAction* toRun = static_cast<IPeriodicAction*>(cdllToRun);
            if(toRun->isReadyToRun()) {
                toRun->restartTimerNoDrift();
                myPeriodicQ.touch();
                toRun->run();
            }
        }

        // -- Run the next action from the background queue. --
        cdllToRun = myBackgroundQ.pop();
        if(cdllToRun != 0) {
            myBackgroundQ.push(*cdllToRun);
            IBackgroundAction* toRun = static_cast<IBackgroundAction*>(cdllToRun);
            toRun->run();
            return;
        }
    }

}}
