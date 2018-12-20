#ifndef LogikEdge_React_List_h
#define LogikEdge_React_List_h

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
struct List {
    // -----------------------------------------------------------------------
    /// Create a self contained list of only itself
    List() {
        next= prev= this;
    }

    // -----------------------------------------------------------------------
    /// Returns the next element of the list.
    template <typename T= List>
    T* getNext() const {
        return static_cast<T*>(next);
    }

    // -----------------------------------------------------------------------
    /// Returns the previous element of the list.
    template <typename T= List>
    T* getPrevious() const {
        return static_cast<T*>(prev);
    }

    // -----------------------------------------------------------------------
    /// Appends an element to the list.
    ///
    /// The List appended will be removed from its current list prior to
    /// joining this new list.
    ///
    /// @param toAdd The list to be added.
    void addAfter(List& toAdd);

    // -----------------------------------------------------------------------
    /// Prepends an element to the list.
    ///
    /// The List appended will be removed from its current list prior to
    /// joining this new list.
    ///
    /// @param toAdd The list to be added.
    void addBefore(List& toAdd) {
        prev->addAfter(toAdd);
    }

    // -----------------------------------------------------------------------
    /// Joins a list after.
    /// @param toAdd Head of the list to be added.
    void joinListAfter(List& toAdd);

    // -----------------------------------------------------------------------
    /// Joins a list before.
    /// @param toAdd Head of the list to be added.
    void joinListBefore(List& toAdd) {
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
    void isolate();

private:
    List*   next;   ///< Next element in the list
    List*   prev;   ///< Previous element in the list
};


}}
#endif
