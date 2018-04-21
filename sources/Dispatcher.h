#ifndef LogikEdge_React_Dispatcher_h
#define LogikEdge_React_Dispatcher_h

#include "CdllQueue.h"


namespace LogikEdge { namespace React {
    // -- Forward declarations --
    struct IAction;

    // =======================================================================
    struct Dispatcher {
        void activate(IAction& toActivate);

        void runOnce();

        static Dispatcher&  getInstance() {
            return ourDispatcher;
        }
    private:
        CdllQueue   myOnEventQ;
        CdllQueue   myBackgroundQ;

        static Dispatcher ourDispatcher;
    };

}}

#endif
