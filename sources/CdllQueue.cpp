#include "CdllQueue.h"

namespace LogikEdge { namespace React {

    Cdll* CdllQueue::pop() {
        Cdll* result = peek();
        if(result != 0) {
            result->isolate();
        }
        return result;
    }

}}
