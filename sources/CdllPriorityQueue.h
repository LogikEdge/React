#ifndef LogikEdge_React_CdllPriorityQueue_h
#define LogikEdge_React_CdllPriorityQueue_h

#include "Cdll.h"

namespace LogikEdge { namespace React {

    // =======================================================================
    struct CdllPriorityQueue {
        typedef int (*SortFunction)(Cdll&, Cdll&);

        CdllPriorityQueue(SortFunction theSortFunction) {
            isSorted = true;
            sortFunction = theSortFunction;
        }

        bool isEmpty() const { return head.isIsolated(); }

        void touch() { isSorted = false; }

        void push(Cdll& toAdd) {
            // -- Add at the end of the queue. --
            head.addBefore(toAdd);

            // -- Schedule a sort operation. --
            isSorted = false;
        }

        Cdll* peek() {
            // -- Assure that the highest priority is on top. --
            sort();
            return head.isIsolated() ? 0 : head.getNext();
        }

        Cdll* pop();

    private:
        void sort();

    private:
        Cdll            head;       //< The head of the Cdll priority queue.
        bool            isSorted;   //< Keeps track of the sorted state.
        SortFunction    sortFunction;
    };
}}

#endif
