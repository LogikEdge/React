#ifndef LogikEdge_React_Cdll_h
#define LogikEdge_React_Cdll_h

namespace LogikEdge { namespace React {

// =======================================================================
/// The Circular Doubly Linked List is a low-level struct used to create
/// containers.  It implements the following capabilities:
///     1) access to both previous and next element
///     2) each element can be the head of its list
///     3) fix performance to access head and tail of a list.
///
/// Ex:
///     --------------------------------------
///     |   ------      ------      ------   |
///     -->| next |--->| next |--->| next |---
///         ------      ------      ------
///     ---| prev |<---| prev |<---| prev |<--
///     |   ------      ------      ------   |
///     --------------------------------------
///
struct Cdll {
    // -----------------------------------------------------------------------
    /// Create a self contained list of only itself
    Cdll() {
        next= prev= this;
    }

    // -----------------------------------------------------------------------
    /// Returns the next element of the list.
    Cdll* getNext() const {
        return next;
    }

    // -----------------------------------------------------------------------
    /// Returns the previous element of the list.
    Cdll* getPrevious() const {
        return prev;
    }

    // -----------------------------------------------------------------------
    /// Appends an element to the list.
    ///
    /// The Cdll appended will be removed from its current list prior to
    /// joining this new list.
    ///
    /// @param toAdd The list to be added.
    void addAfter(Cdll& toAdd) {
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
    /// Prepends an element to the list.
    ///
    /// The Cdll appended will be removed from its current list prior to
    /// joining this new list.
    ///
    /// @param toAdd The list to be added.
    void addBefore(Cdll& toAdd) {
        prev->addAfter(toAdd);
    }

    // -----------------------------------------------------------------------
    /// Joins a list after.
    /// @param toAdd Head of the list to be added.
    void joinListAfter(Cdll& toAdd) {
        toAdd.prev->next= next;
        next->prev= toAdd.prev;
        next= &toAdd;
        toAdd.prev= this;
    }

    // -----------------------------------------------------------------------
    /// Joins a list before.
    /// @param toAdd Head of the list to be added.
    void joinListBefore(Cdll& toAdd) {
        prev->joinListAfter(toAdd);
    }

    // -----------------------------------------------------------------------
    /// Tests if this element is a self contained list.
    /// @return true if this is a self contained list.  false otherwise.
    bool isIsolated() const {
        return next == this;
    }

    // -----------------------------------------------------------------------
    /// Isolates the current element from the containing list.
    void isolate() {
        prev->next= next;
        next->prev= prev;
        next= prev= this;
    }

private:
    Cdll*   next;   ///< Next element in the list
    Cdll*   prev;   ///< Previous element in the list
};

}}


}}
#endif
