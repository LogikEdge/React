#ifndef LogikEdge_React_Dispatcher_h
#define LogikEdge_React_Dispatcher_h

#include "CdllQueue.h"
#include "CdllPriorityQueue.h"

namespace LogikEdge { namespace React {
    // -- Forward declarations --
    struct IAction;

    extern int dummyCompare(Cdll&, Cdll&);

    // =======================================================================
    struct Dispatcher {
        Dispatcher() : myDelayQ(dummyCompare), myPeriodicQ(dummyCompare) {}

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
