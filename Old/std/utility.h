#if defined(ARDUINO)
#ifndef _std_utility_H
#define _std_utility_H

namespace std {
    // TODO: Review & comment this file.

    // =======================================================================
    // Move some of the types from global space to the std namespace
    // =======================================================================
    typedef ::size_t    size_t;     //< Type that represents a memory size quantity
    typedef ::ptrdiff_t ptrdiff_t;  //< Type that represents an integer distance
                                    //< between two memory location

    // =======================================================================
    // Relational operators
    //
    // The minimum relational operator that must be defined is:
    //      operator ==(...)
    //      operator < (...)
    // =======================================================================
    template <typename T1, typename T2>
    inline bool operator != (const T1& lhs, const T2& rhs) { return !(lhs == rhs); }
    template <typename T1, typename T2>
    inline bool operator >= (const T1& lhs, const T2& rhs) { return !(lhs < rhs); }
    template <typename T1, typename T2>
    inline bool operator > (const T1& lhs, const T2& rhs) { return (lhs >= rhs) && (lhs != rhs); }
    template <typename T1, typename T2>
    inline bool operator <= (const T1& lhs, const T2& rhs) { return !(lhs > rhs); }

    // =======================================================================
    /// Swaps the value of two variables of the same type.
    ///
    /// @param a    The first variable in the swap
    /// @param b    The second varibale in the swap
    template <typename T>
    inline void swap(T& a, T& b) {
        T c= a;
        a= b;
        b= c;
    }

}

#endif
#endif
