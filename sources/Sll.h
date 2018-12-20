#ifndef React_Sll_h
#define React_Sll_h

namespace React {

// =======================================================================
/// The Single Linked List is a low-level struct used to create
/// containers.  It implements the following capabilities:
///     1) access next element
///     2) each element can be the head of its list
///     3) fix performance to access head of a list.
///
/// Ex:
///      ------      ------      ------
///     | next |--->| next |--->| next |---> NULL
///      ------      ------      ------
///
struct Sll {
    // -----------------------------------------------------------------------
    /// Create a self contained list of only itself
    Sll() {
        next= 0;
    }

    // -----------------------------------------------------------------------
    /// Returns the next element of the list.
    Sll* getNext() const {
        return next;
    }

    // -----------------------------------------------------------------------
    /// Adds an element to the top of the list.
    ///
    /// @param toAdd The element to be added.
    void add(Sll& toAdd);

    // -----------------------------------------------------------------------
    /// Removes the next element from the list.
    /// @return The element removed or zero (0).
    Sll* removeNext() {
      Sll* result = next;
      if(result == 0) return 0;
      next = result->next;
      result->next = 0;
      return result;
    }

    // -----------------------------------------------------------------------
    /// Tests if this element is the last in the list.
    /// @return true if this is a self contained list.  false otherwise.
    bool isLast() const {
        return next == 0;
    }

private:
    Sll*   next;   ///< Next element in the list
};


}
#endif
