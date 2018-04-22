#include "Dispatcher.h"
#include "IAction.h"

namespace LogikEdge { namespace React {

    Dispatcher Dispatcher::ourDispatcher;

    int dummyCompare(Cdll&, Cdll&) { return 0; }

    void Dispatcher::activate(IAction& toActivate) {
        switch(toActivate.getExecutionState()) {
        case IAction::OnEvent:
            activateOnEvent(toActivate);
            break;
        case IAction::Background:
            activateInBackground(toActivate);
            break;
        case IAction::Periodic:
            activatePeriodic(toActivate);
            break;
        case IAction::AfterDelay:
            activateAfterDelay(toActivate);
            break;
        }
    }

    void Dispatcher::activateOnEvent(IAction& toActivate) {
        myOnEventQ.push(toActivate);
    }
    void Dispatcher::activateAfterDelay(IAction& toActivate) {
        toActivate.myTimer.start(toActivate.myDelay);
        myDelayQ.push(toActivate);
    }
    void Dispatcher::activatePeriodic(IAction& toActivate) {
        toActivate.myTimer.start(toActivate.myDelay);
        myPeriodicQ.push(toActivate);
    }
    void Dispatcher::activateInBackground(IAction& toActivate) {
        myBackgroundQ.push(toActivate);
    }

    void Dispatcher::runOnce() {
        // -- First empty the OnEvent queue. --
        Cdll* cdllToRun = myOnEventQ.pop();
        if(cdllToRun != 0) {
            IAction* toRun = static_cast<IAction*>(cdllToRun);
            toRun->run();
            return;
        }

        cdllToRun = myDelayQ.peek();
        if(cdllToRun != 0) {
            IAction* toRun = static_cast<IAction*>(cdllToRun);
            if(toRun->myTimer.isElapsed()) {
                myDelayQ.pop();
                toRun->run();
            }
        }

        cdllToRun = myPeriodicQ.peek();
        if(cdllToRun != 0) {
            IAction* toRun = static_cast<IAction*>(cdllToRun);
            if(toRun->myTimer.isElapsed()) {
                toRun->myTimer.restartNoDrift(toRun->myDelay);
                myPeriodicQ.touch();
                toRun->run();
            }
        }

        // -- Run the next action from the background queue. --
        cdllToRun = myBackgroundQ.pop();
        if(cdllToRun != 0) {
            myBackgroundQ.push(*cdllToRun);
            IAction* toRun = static_cast<IAction*>(cdllToRun);
            toRun->run();
            return;
        }
    }

}}
