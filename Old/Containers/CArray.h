#ifndef _LogikEdge_React_CArray_h
#define _LogikEdge_React_CArray_h

namespace LogikEdge { namespace React {

template <typename T, unsigned S>
class CArray {

public:
	typedef void        Base;
    typedef CArray<T,S> Type;
    typedef T           ValueType;

    struct ForwardIterator {
		typedef void						Base;
        typedef CArray<T,S>             	Container;
        typedef Container::ForwardIterator	Type;
        typedef Container::ValueType		ValueType;

        ForwardIterator(ValueType* cursor) : myCursor(cursor) {}
        ForwardIterator(const ForwardIterator& other) { myCursor= other.myCursor; }

        ValueType&          operator*() const   { return *myCursor; }
        ForwardIterator&	operator++()        { ++myCursor; return *this; }
        ForwardIterator    	operator++(int _)   { Iterator tmp= *this; ++myCursor; return tmp; }
        bool        		operator!=(const ForwardIterator& other) const { return myCursor != other.myCursor; }

    protected:
        ValueType*  myCursor;
    };
	typedef ForwardIterator	Iterator;


    static const unsigned size= S;
    static       unsigned count() { return S; }

    ValueType&  operator[](unsigned idx) { return myArray[idx]; }

    // Iterator limits
    Iterator    begin() const { return Iterator(myArray); }
    Iterator    end()   const { return Iterator(&myArray[S]); }

private:
    T   myArray[S];
};

}}

#endif
