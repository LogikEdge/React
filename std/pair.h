#ifndef _std_pair_H
#define _std_pair_H

#include "utility.h"

namespace std {
    // TODO: Review and comment this file.
    // =======================================================================
    /// This class couples together a pair of values, which may be of
    /// different types (T1 and T2). The individual values can be accessed
    /// through its public members first and second.
    ///
    /// @param T1   Type of member first
    /// @param T2   Type of member second
    ///
    template <typename T1, typename T2>
    struct pair {
        typedef T1  first_type;
        typedef T2  second_type;

        first_type  first;
        second_type second;

        pair(const pair<first_type, second_type>& p)    { first= p.first; second= p.second; }
        pair(const first_type& a, const second_type& b) { first= a; second= b; }

        pair&   operator=(const pair& p)    { first= p.first; second= p.second; return p; }

        void    swap(pair& p)               { swap(first, p.first); swap(second, p.second); }
    };

    // =======================================================================
    /// Compares two pairs for equality.
    ///
    /// @param lhs  Left hand side variable
    /// @param rhs  Right hand side variable
    template <typename T1, typename T2>
    bool operator == (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }
    // =======================================================================
    /// Determines if lhs pair is lower then rhs pair.  The lexical comparaison
    /// is done in order of first then second attribute.
    ///
    /// @param lhs  Left hand side variable
    /// @param rhs  Right hand side variable
    template <typename T1, typename T2>
    bool operator < (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
        return lhs.first == rhs.first ? lhs.second < rhs.second : lhs.first < rhs.first;
    }
    // =======================================================================
    /// Returns the element of the pair of the given index.
    template <unsigned I, typename T> class tuple_element;
    template <typename T1, typename T2> struct tuple_element<0, pair<T1,T2> > {
        typedef T1  type;
    };
    template <typename T1, typename T2> struct tuple_element<1, pair<T1,T2> > {
        typedef T2  type;
    };

    // =======================================================================
    /// Creates a pair from two given variables.
    ///
    /// @param a    The first variable
    /// @param b    The second variable
    template <typename T1, typename T2>
    pair<T1,T2> make_pair(T1 a, T2 b) {
        return pair<T1,T2>(a,b);
    }
}

#endif
