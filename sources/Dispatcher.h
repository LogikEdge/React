#ifndef LogikEdge_React_Dispatcher_h
#define LogikEdge_React_Dispatcher_h

#include "CdllQueue.h"
#include "CdllPriorityQueue.h"

namespace LogikEdge { namespace React {
    // -- Forward declarations --
    struct IAction;
    struct IOnEventAction;
    struct IDelayedAction;
    struct IPeriodicAction;
    struct IBackgroundAction;

    extern int dummyCompare(Cdll&, Cdll&);

    // =======================================================================
    struct Dispatcher {
        Dispatcher() : myDelayQ(dummyCompare), myPeriodicQ(dummyCompare) {}

        void activate(IOnEventAction&);
        void activate(IDelayedAction&);
        void activate(IPeriodicAction&);
        void activate(IBackgroundAction&);

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
