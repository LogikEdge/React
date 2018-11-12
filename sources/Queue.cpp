#include "Queue.h"

namespace LogikEdge { namespace React {

    List* Queue::pop() {
        List* result = peek();
        if(result != 0) {
            result->isolate();
        }
        return result;
    }

}}
