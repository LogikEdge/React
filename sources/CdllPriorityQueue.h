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

        Cdll* pop() {
            // -- Get highest priority element. --
            Cdll* result = peek();
            if(result == 0) {
                return 0;
            }

            // -- Remove highest priority element from the queue. --
            result->isolate();
            isSorted = false;
        }

        bool isEmpty() const {
            return head.isIsolated();
        }

    private:
        void sort() {
            // -- Nothing to do if queue is already sorted. --
            if(isSorted == true) {
                return;
            }
            // -- Find the highest priority element. --
            Cdll* best = head.getNext();
            if(best == &head) {
                isSorted = true;
                return;
            }
            // -- Put the highest priority on top of the queue. --
            if(best != head.getNext()) {
                head.addAfter(*best);
            }
            // -- Declare queue sorted. --
            isSorted = true;
        }

    private:
        Cdll            head;       //< The head of the Cdll priority queue.
        bool            isSorted;   //< Keeps track of the sorted state.
        SortFunction    sortFunction;
    };
}}

#endif
