#include "Queue.h"

namespace React {

    List* Queue::pop() {
        List* result = peek<List>();
        if(result != 0) {
            result->isolate();
        }
        return result;
    }

}
