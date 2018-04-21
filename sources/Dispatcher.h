#ifndef LogikEdge_React_Dispatcher_h
#define LogikEdge_React_Dispatcher_h

#include "CdllQueue.h"
#include "CdllPriorityQueue.h"

namespace LogikEdge { namespace React {
    // -- Forward declarations --
    struct IAction;

    // =======================================================================
    struct Dispatcher {
        Dispatcher() : myDelayQ(0), myPeriodicQ(0) {}

        void activate(IAction& toActivate);

        void runOnce();

        static Dispatcher&  getInstance() {
            return ourDispatcher;
        }
    private:
        CdllQueue           myOnEventQ;
        CdllQueue           myBackgroundQ;
        CdllPriorityQueue   myDelayQ;
        CdllPriorityQueue   myPeriodicQ;

        static Dispatcher   ourDispatcher;
    };

}}

#endif
