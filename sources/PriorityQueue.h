#ifndef LogikEdge_React_PriorityQueue_h
#define LogikEdge_React_PriorityQueue_h

#include "List.h"

namespace LogikEdge { namespace React {

    // =======================================================================
    struct PriorityQueue {
        typedef int (*SortFunction)(const List&, const List&);

        PriorityQueue(SortFunction theSortFunction) {
            isSorted = true;
            sortFunction = theSortFunction;
        }

        bool isEmpty() const { return head.isIsolated(); }

        void touch() { isSorted = false; }

        void push(List& toAdd) {
            // -- Add at the end of the queue. --
            head.addBefore(toAdd);

            // -- Schedule a sort operation. --
            isSorted = false;
        }

        List* peek() {
            // -- Assure that the highest priority is on top. --
            sort();
            return head.isIsolated() ? 0 : head.getNext();
        }

        List* pop();

    private:
        void sort();

    private:
        List            head;       //< The head of the List priority queue.
        bool            isSorted;   //< Keeps track of the sorted state.
        SortFunction    sortFunction;
    };
}}

#endif
