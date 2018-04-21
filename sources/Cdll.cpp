#include "Cdll.h"

namespace LogikEdge { namespace React {

// -----------------------------------------------------------------------
/// Appends an element to the list.
///
/// The Cdll appended will be removed from its current list prior to
/// joining this new list.
///
/// @param toAdd The list to be added.
void Cdll::addAfter(Cdll& toAdd) {
    // -- Remove element to add from its current list. --
    toAdd.isolate();

    // -- Setup new element to join the list. --
    toAdd.previous = this;
    toAdd.next = next;

    // -- Insert the new element into the list. --
    next->previous= &toAdd;
    next = &toAdd;
}

// -----------------------------------------------------------------------
/// Joins a list after.
/// @param toAdd Head of the list to be added.
void Cdll::joinListAfter(Cdll& toAdd) {
    toAdd.prev->next= next;
    next->prev= toAdd.prev;
    next= &toAdd;
    toAdd.prev= this;
}

// -----------------------------------------------------------------------
/// Isolates the current element from the containing list.
void Cdll::isolate() {
    prev->next= next;
    next->prev= prev;
    next= prev= this;
}

}}
