#include "List.h"

namespace React {

// -----------------------------------------------------------------------
/// Appends an element to the list.
///
/// The List appended will be removed from its current list prior to
/// joining this new list.
///
/// @param toAdd The list to be added.
void List::addAfter(List& toAdd) {
    // -- Remove element to add from its current list. --
    toAdd.isolate();

    // -- Setup new element to join the list. --
    toAdd.prev = this;
    toAdd.next = next;

    // -- Insert the new element into the list. --
    next->prev= &toAdd;
    next = &toAdd;
}

// -----------------------------------------------------------------------
/// Joins a list after.
/// @param toAdd Head of the list to be added.
void List::joinListAfter(List& toAdd) {
    toAdd.prev->next= next;
    next->prev= toAdd.prev;
    next= &toAdd;
    toAdd.prev= this;
}

// -----------------------------------------------------------------------
/// Isolates the current element from the containing list.
void List::isolate() {
    prev->next= next;
    next->prev= prev;
    next= prev= this;
}

}
