#ifndef LogikEdge_React_IAction_h
#define LogikEdge_React_IAction_h

#include "Cdll.h"
#include "Dispatcher.h"
#include "Timer.h"

namespace LogikEdge { namespace React {

    // =======================================================================
    struct IAction : private Cdll {
        /// Action execution state.
        enum ExecutionState { Immediate, OnEvent, AfterDelay, Periodic, Background };

        IAction(ExecutionState theExecutionState = OnEvent) {
            myExecutionState = theExecutionState;
        }
        IAction(ExecutionState theExecutionState, Millisecond theDelay) {
            myExecutionState = theExecutionState;
            myDelay = theDelay;
        }


        void activate() {
            if(myExecutionState == Immediate) {
                run();
                return;
            }
            Dispatcher::getInstance().activate(*this);
        }

        bool isActive() const {
            return !isIsolated();
        }

        // ------------------------------------------------------------------
        /// The specialization of the Action.
        virtual void run()= 0;

        ExecutionState getExecutionState() const {
            return myExecutionState;
        }

        friend struct Dispatcher;

    private:
        ExecutionState  myExecutionState;   //< Execution state of the action.
        Timer           myTimer;            //< Timer used for periodic and delayed execution.
        Millisecond     myDelay;
    };

}}
#endif
