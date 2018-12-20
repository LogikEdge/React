#ifndef React_Dispatcher_h
#define React_Dispatcher_h

#include "Queue.h"
#include "PriorityQueue.h"

namespace React {
    // -- Forward declarations --
    struct IAction;
    struct IOnEventAction;
    struct IDelayedAction;
    struct IPeriodicAction;
    struct IBackgroundAction;

    extern int timedActionCompare(const List&, const List&);

    // =======================================================================
    struct Dispatcher {
        Dispatcher() : myDelayQ(timedActionCompare), myPeriodicQ(timedActionCompare) {}

        void activate(IOnEventAction&);
        void activate(IDelayedAction&);
        void activate(IPeriodicAction&);
        void activate(IBackgroundAction&);

        void runOnce();

        static Dispatcher&  getInstance() { return ourDispatcher; }
        //static int          timedActionCompare(const List&, const List&);

    private:
        Queue           myOnEventQ;
        Queue           myBackgroundQ;
        PriorityQueue   myDelayQ;
        PriorityQueue   myPeriodicQ;

        static Dispatcher   ourDispatcher;
    };

}

#endif
