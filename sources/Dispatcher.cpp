#include "Dispatcher.h"
#include "IAction.h"

namespace LogikEdge { namespace React {

    Dispatcher Dispatcher::ourDispatcher;

    void Dispatcher::activate(IAction& toActivate) {
        switch(toActivate.getExecutionState()) {
        case IAction::OnEvent:
            myOnEventQ.push(toActivate);
            break;
        case IAction::Background:
            myBackgroundQ.push(toActivate);
            break;
        }
    }

    void Dispatcher::runOnce() {
        // -- First empty the OnEvent queue. --
        Cdll* cdllToRun = myOnEventQ.pop();
        if(cdllToRun != 0) {
            IAction* toRun = static_cast<IAction*>(cdllToRun);
            toRun->run();
            return;
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
