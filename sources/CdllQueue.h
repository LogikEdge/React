#ifndef LogikEdge_React_CdllQueue_h
#define LogikEdge_React_CdllQueue_h

#include "Cdll.h"

namespace LogikEdge { namespace React {

    // =======================================================================
    struct CdllQueue {

        void push(Cdll& toAdd) {
            head.addBefore(toAdd);
        }

        Cdll* peek() const {
            return head.isIsolated() ? 0 : head.getNext();
        }

        Cdll* pop();

    private:
        Cdll    head;   //< The head of the Cdll queue.
    };
}}

#endif
