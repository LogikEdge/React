#ifndef React_Queue_h
#define React_Queue_h

#include "List.h"

namespace React {

    // =======================================================================
    struct Queue {

        void push(List& toAdd) {
            head.addBefore(toAdd);
        }

        template <typename T>
        T* peek() const {
            return head.isIsolated() ? 0 : head.getNext<T>();
        }

        List* pop();

        bool isEmpty() const {
            return head.isIsolated();
        }

    private:
        List    head;   //< The head of the List queue.
    };
}

#endif
