#ifndef LogikEdge_React_Queue_h
#define LogikEdge_React_Queue_h

#include "List.h"

namespace LogikEdge { namespace React {

    // =======================================================================
    struct Queue {

        void push(List& toAdd) {
            head.addBefore(toAdd);
        }

        List* peek() const {
            return head.isIsolated() ? 0 : head.getNext();
        }

        List* pop();

        bool isEmpty() const {
            return head.isIsolated();
        }

    private:
        List    head;   //< The head of the List queue.
    };
}}

#endif
