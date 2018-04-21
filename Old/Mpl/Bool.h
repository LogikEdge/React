#ifndef _LogikEdge_Mpl_Bool_h
#define _LogikEdge_Mpl_Bool_h

namespace LogikEdge { namespace Mpl {

    template <bool V>
    struct Bool {
        typedef Bool<V>     Type;
        typedef Bool<!V>    NotType;
        
        static const bool   value= V;
    };
    
    typedef Bool<true>  TrueType;   //< Alias for a Bool type that is true.
    typedef Bool<false> FalseType;  //< Alias for a Bool type that is false.
    
}}

#endif
