#ifndef _std_allocator_h
#define _std_allocator_h

namespace std {

    template <typename T> struct allocator;
    
    // =======================================================================
    /// The std::_allocator class template is the base for all allocators used
    /// by all standard library containers.  It provides usefull type
    /// definitions for all allocators that we be defined.
    ///
    /// @param  T   The type for which to allocate memory for.
    ///
    template <typename T>
    struct _allocatorBase {
        typedef T           value_type;         //< Element type
        typedef T*          pointer;            //< Pointer to element
        typedef T&          reference;          //< Reference to element
        typedef const T*    const_pointer;      //< Pointer to constant element
        typedef const T&    const_reference;    //< Reference to constanr element
        typedef size_t      size_type;          //< Quantity of elements
        typedef ptrdiff_t   difference_type;    //< Difference between two pointers
        template <typename U> struct rebind {
            /// Its member type _other_ is the equivalent allocator type to allocate
            /// elements of type _Type_.
            typedef allocator<U>    other; 
        };
    };
        
    // =======================================================================
    /// The std::allocator class template is the default Allocator used by all
    /// standard library containers if no user-specified allocator is
    /// provided. The default allocator is stateless, that is, all instances
    /// of the given allocator are interchangeable, compare equal and can
    /// deallocate memory allocated by any other instance of the same
    /// allocator type.
    ///
    /// @param  T   The type for which to allocate memory for.
    ///
    template <typename T>
    struct allocator : _allocatorBase<T> {
        static T*      allocate(size_t n, const void* hint)    { return allocate(n); }
        static T*      allocate(size_t n)                      { return ::operator new(n * sizeof(T)); }
        static void    deallocate(T* p, size_t n)              { delete p; }
    };

    // =======================================================================
    /// Specialization for void lacks the member typedefs reference,
    /// const_reference, size_type and difference_type. This specialization
    /// declares no member functions.
    template <>
    struct allocator<void> {
        typedef void        value_type;         //< Element type
        typedef void*       pointer;            //< Pointer to element
        typedef const void* const_pointer;      //< Pointer to constant element
        typedef size_t      size_type;          //< Quantity of elements
        typedef ptrdiff_t   difference_type;    //< Difference between two pointers
        template <typename U> struct rebind {
            /// Its member type _other_ is the equivalent allocator type to allocate
            /// elements of type _Type_.
            typedef allocator<U>    other; 
        };    
    };
}

#endif
