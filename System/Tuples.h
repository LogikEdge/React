#ifndef _LogikEdge_Seal_Tuples_h
#define _LogikEdge_Seal_Tuples_h

namespace LogikEdge { namespace Seal {

    template <typename T1, typename T2>
    class Pair {
    public:
        typedef void        Base;
        typedef Pair<T1,T2> Type;
        typedef T1          Item1Type;
        typedef T2          Item2Type;

        Pair(const Item1Type& t1, const Item2Type& t2) { item1= t1; item2= t2; }
        
        Item1Type  item1;  //< The first item of the pair.
        Item2Type  item2;  //< The second item of the pair.
    };
    
    template <typename KeyType_, typename ValueType_>
    class KeyValuePair : public Pair<KeyType_, ValueType_> {
    public:
        typedef KeyType_                        KeyType;
        typedef ValueType_                      ValueType;
        typedef Pair<KeyType,ValueType>         Base;
        typedef KeyValuePair<KeyType,ValueType> Type;
        
        KeyValuePair(const KeyType& key, const ValueType& value)
            : Base(key,value) {}
        
        KeyType     getKey()   const { return Base::item1; }
        ValueType   getValue() const { return Base::item2; }
    };
    
    template <typename T1, typename T2, typename T3>
    class Triple {
    public:
        typedef void                Base;
        typedef Triple<T1,T2,T3>    Type;
        typedef T1                  Item1Type;
        typedef T2                  Item2Type;
        typedef T3                  Item3Type;

        Triple(const Item1Type& t1, const Item2Type& t2, const Item3Type& t3) {
            item1= t1; item2= t2; item3= t3;
        }
        
        Item1Type  item1;  //< The first item in the triple.
        Item2Type  item2;  //< The second item in the triple.
        Item3Type  item3;  //< The third item in the triple.
    };
    
}}

#endif
