#ifndef _std_vector_h
#define _std_vector_h

#include "utility.h"
#include "allocator.h"

namespace std {
    // TODO: Complete the vector container type.
    
    // =======================================================================
    /// The storage of the vector is handled automatically, being expanded and
    /// contracted as needed. Vectors usually occupy more space than static
    /// arrays, because more memory is allocated to handle future growth. This
    /// way a vector does not need to reallocate each time an element is
    /// inserted, but only when the additional memory is exhausted. The total
    /// amount of allocated memory can be queried using capacity() function.
    /// Extra memory can be returned to the system via a call to
    /// shrink_to_fit().
    ///
    /// Reallocations are usually costly operations in terms of performance.
    /// reserve() function can be used to eliminate reallocations if the
    /// number of elements is known beforehand.
    ///
    /// @param T    The type to be contained into the vector
    /// @param Allocator    The allocator type to be used by the vector
    /// 
    template <typename T, typename Allocator= std::allocator<T> >
    class vector {
    public:
        typedef T                                   value_type;
        typedef Allocator                           allocator_type;
        typedef size_t                              size_type;
        typedef ptrdiff_t                           difference_type;
        typedef typename Allocator::reference       reference;
        typedef typename Allocator::const_reference const_reference;
        typedef typename Allocator::pointer         pointer;
        typedef typename Allocator::const_pointer   const_pointer;

        bool        empty() const       { return mySize == 0; } //< Checks whether the container is empty
        size_type   size() const        { return mySize; }      //< Returns the number of elements
        size_type   capacity() const    { return myCapacity; }  //< Returns maximum number of element that can be held without reallocation
        
    private:
        size_type   myCapacity;
        size_type   mySize;
        pointer     myContainer;
    };
}

#endif