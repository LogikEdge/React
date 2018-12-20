#include "PriorityQueue.h"

namespace LogikEdge { namespace React {

    List* PriorityQueue::pop() {
        // -- Get highest priority element. --
        List* result = peek();
        if(result == 0) {
            return 0;
        }

        // -- Remove highest priority element from the queue. --
        result->isolate();
        isSorted = false;
    }

    void PriorityQueue::sort() {
        // -- Nothing to do if queue is already sorted. --
        if(isSorted == true) {
            return;
        }
        // -- Nothing to do if the queue is empty. --
        List* best = head.getNext();
        if(best == &head) {
            isSorted = true;
            return;
        }
        // -- Find the highest priority element. --
        for(List* cursor = best->getNext(); cursor != &head; cursor = cursor->getNext()) {
            if(sortFunction(*best, *cursor) < 0) {
                best = cursor;
            }
        }
        // -- Put the highest priority on top of the queue. --
        if(best != head.getNext()) {
            head.addAfter(*best);
        }
        // -- Declare queue sorted. --
        isSorted = true;
    }

}}
