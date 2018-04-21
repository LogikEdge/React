#ifndef LogikEdge_React_IExecutable_h
#define LogikEdge_React_IExecutable_h

namespace LogikEdge { namespace React {

    // =======================================================================
    /// The _IExecutable_ is the fundamental unit of execution of _React_.
    ///
    /// Override the function 'doRun()' to provide your own specialized
    /// functionality.
    struct IExecutable {
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

    // -- Action with 1 parameter. --
    template <typename T>
    struct IExecutable1 {
        virtual void operator()(T p1) { doRun(p1); }
    protected:
        virtual void doRun(T)= 0;
    };

    // -- Action with 2 parameter. --
    template <typename T1, typename T2>
    struct IExecutable2 {
        virtual void operator()(T1 p1, T2 p2) { doRun(p1, p2); }
    protected:
        virtual void doRun(T1, T2)= 0;
    };

    // -- Action with 3 parameter. --
    template <typename T1, typename T2, typename T3>
    struct IExecutable3 {
        virtual void operator()(T1 p1, T2 p2, T3 p3) { doRun(p1, p2, p3); }
    protected:
        virtual void doRun(T1, T2, T3)= 0;
    };

}}

#endif

