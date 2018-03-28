#ifndef _std_array_h
#define _std_array_h

#include "utility.h"

namespace std {
    
    // ======================================================================
    /// The following defines an array container compatible with the C++14
    /// standard library.
    ///
    /// @reference http://en.cppreference.com/w/cpp/container/array
    ///
    template <typename T, std::size_t N>
    struct array {
        typedef T                   value_type;
        typedef std::size_t         size_type;
        typedef std::ptrdiff_t      difference_type;
        typedef value_type&         reference;
        typedef const value_type&   const_reference;
        typedef value_type*         pointer;
        typedef const value_type*   const_pointer;
        
        // Array storage
        T   myData[N];
        
        // Element access
        T&          at(unsigned idx)                { return idx < N ? myData[idx] : myData[N-1]; }
        const T&    at(unsigned idx) const          { return idx < N ? myData[idx] : myData[N-1]; }
        T&          operator[](unsigned idx)        { return myData[idx]; }
        const T&    operator[](unsigned idx) const  { return myData[idx]; }
        T&          front()                         { return myData[0]; }
        const T&    front() const                   { return myData[0]; }
        T&          back()                          { return myData[N]; }
        const T&    back() const                    { return myData[N]; }
        T*          data()                          { return myData; }
        const T*    data() const                    { return myData; }
        
        // Capacity
        bool    empty() const       { return N == 0; }
        bool    size() const        { return N; }
        bool    max_size() const    { return N; }
        
        // Operations
        void fill(const T& value)   { for(int i= 0; i < N; ++i) { myData[i]= value; }}
        
        struct BidirectionalIterator {
            BidirectionalIterator(array<T,N>& container, unsigned cursor= 0)
                : myContainer(container) { myCursor= cursor; }
            
            // Validity
            operator bool() { return myCursor < N; }

            // Cursor movement
            BidirectionalIterator&  operator++()    { if(myCursor < N) ++myCursor; return *this; }
            BidirectionalIterator&  operator--()    { if(myCursor != 0) --myCursor; return *this; }
            BidirectionalIterator   operator++(int) { BidirectionalIterator tmp= *this; (*this)++; return tmp; }
            BidirectionalIterator   operator--(int) { BidirectionalIterator tmp= *this; (*this)--; return tmp; }
            BidirectionalIterator&  operator+=(int x)   { myCursor = addToCursor(x); return *this; }
            BidirectionalIterator&  operator-=(int x)   { myCursor = addToCursor(-x); return *this; }
            unsigned                addToCursor(int x)  { int t= myCursor+x; if(t < 0) t= 0; if(t > N) t= N; return t; }
            
            // Element access
            T&  operator[](int i)   { unsigned cursor= addToCursor(i); return myContainer[cursor > N-1 ? N-1 : cursor]; }
            
        private:
            array<T,N>&     myContainer;
            unsigned        myCursor;
        };
    };
}

#endif
