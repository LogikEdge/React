#ifndef _LogikEdge_React_Func_h
#define _LogikEdge_React_Func_h

#include "Nil.h"

namespace LogikEdge { namespace React {

    // ======================================================================
    /// The Func<...> template facilitates the creation of function pointer
    /// types.  It is used to define function pointer with a return type and
    /// 0 to 9 parameter types.
    ///
    /// @param R    The return type.
    /// @param P1-9 The parameter types (optional).

    /// 9 parameters.
    template <typename R, typename P1 = Nil,
                          typename P2 = Nil,
                          typename P3 = Nil,
                          typename P4 = Nil,
                          typename P5 = Nil,
                          typename P6 = Nil,
                          typename P7 = Nil,
                          typename P8 = Nil,
                          typename P9 = Nil>
    struct Func { typedef R (*Type)(P1,P2,P3,P4,P5,P6,P7,P8,P9); };

    /// 0 parameter
    template <typename R>
    struct Func<R,Nil,Nil,Nil,Nil,Nil,Nil,Nil,Nil,Nil> { typedef R (*Type)(); };

    /// 1 parameter
    template <typename R, typename P1>
    struct Func<R,P1,Nil,Nil,Nil,Nil,Nil,Nil,Nil,Nil> { typedef R (*Type)(P1); };

    /// 2 parameters
    template <typename R, typename P1,
                          typename P2>
    struct Func<R,P1,P2,Nil,Nil,Nil,Nil,Nil,Nil,Nil> { typedef R (*Type)(P1,P2); };

    /// 3 parameters
    template <typename R, typename P1,
                          typename P2,
                          typename P3>
    struct Func<R,P1,P2,P3,Nil,Nil,Nil,Nil,Nil,Nil> { typedef R (*Type)(P1,P2,P3); };

    /// 4 parameters
    template <typename R, typename P1,
                          typename P2,
                          typename P3,
                          typename P4>
    struct Func<R,P1,P2,P3,P4,Nil,Nil,Nil,Nil,Nil> { typedef R (*Type)(P1,P2,P3,P4); };

    /// 5 parameters
    template <typename R, typename P1,
                          typename P2,
                          typename P3,
                          typename P4,
                          typename P5>
    struct Func<R,P1,P2,P3,P4,P5,Nil,Nil,Nil,Nil> { typedef R (*Type)(P1,P2,P3,P4,P5); };

    /// 6 parameters
    template <typename R, typename P1,
                          typename P2,
                          typename P3,
                          typename P4,
                          typename P5,
                          typename P6>
    struct Func<R,P1,P2,P3,P4,P5,P6,Nil,Nil,Nil> { typedef R (*Type)(P1,P2,P3,P4,P5,P6); };

    /// 7 parameters
    template <typename R, typename P1,
                          typename P2,
                          typename P3,
                          typename P4,
                          typename P5,
                          typename P6,
                          typename P7>
    struct Func<R,P1,P2,P3,P4,P5,P6,P7,Nil,Nil> { typedef R (*Type)(P1,P2,P3,P4,P5,P6,P7); };

    /// 8 parameters
    template <typename R, typename P1,
                          typename P2,
                          typename P3,
                          typename P4,
                          typename P5,
                          typename P6,
                          typename P7,
                          typename P8>
    struct Func<R,P1,P2,P3,P4,P5,P6,P7,P8,Nil> { typedef R (*Type)(P1,P2,P3,P4,P5,P6,P7,P8); };

    // ======================================================================
    /// The Action<...> template facilitates the creation of function pointer
    /// types.  It is used to define function pointer without a return type
    /// and 0 to 9 parameter types.
    ///
    /// @param P1-9 The parameter types (optional).
    template <typename P1 = Nil,
              typename P2 = Nil,
              typename P3 = Nil,
              typename P4 = Nil,
              typename P5 = Nil,
              typename P6 = Nil,
              typename P7 = Nil,
              typename P8 = Nil,
              typename P9 = Nil>
    struct Action : public Func<void,P1,P2,P3,P4,P5,P6,P7,P8,P9> {};
}}

#endif

