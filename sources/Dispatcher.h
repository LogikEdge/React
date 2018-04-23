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

    extern int timedActionCompare(const Cdll&, const Cdll&);

    // =======================================================================
    struct Dispatcher {
        Dispatcher() : myDelayQ(timedActionCompare), myPeriodicQ(timedActionCompare) {}

        void activate(IOnEventAction&);
        void activate(IDelayedAction&);
        void activate(IPeriodicAction&);
        void activate(IBackgroundAction&);

        void runOnce();

        static Dispatcher&  getInstance() { return ourDispatcher; }
        static int          timedActionCompare(const Cdll&, const Cdll&);

    private:
        CdllQueue           myOnEventQ;
        CdllQueue           myBackgroundQ;
        CdllPriorityQueue   myDelayQ;
        CdllPriorityQueue   myPeriodicQ;

        static Dispatcher   ourDispatcher;
    };

}}

#endif
