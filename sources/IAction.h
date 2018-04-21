#ifndef LogikEdge_React_IAction_h
#define LogikEdge_React_IAction_h

namespace LogikEdge { namespace React {

    // =======================================================================
    /// The _IAction_ is the fundamental unit of execution of _React_.
    ///
    /// Override the function 'doRun()' to provide your own specialized
    /// functionality.
    struct IAction {
        // ------------------------------------------------------------------
        /// Execution entry point of the action.
        ///
        /// By default, this function will execute the _doRun()_ function.
        /// This function can be overriden to control the execution flow.
        virtual void operator()() { doRun(); }

    protected:
        // ------------------------------------------------------------------
        /// The specialization of the Action.
        virtual void doRun()= 0;
    };
}}
