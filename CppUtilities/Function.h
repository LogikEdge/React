#ifndef _LogikEdge_Seal_Function_h
#define _LogikEdge_Seal_Function_h

// =================================================================
/// Allows to declare a function within another function body.
///
/// @param RET      The function return type.
/// @param NAME     The function name.
/// @param PARAM    The function parameter list.
/// @param CODE     The function code body.
///
#define CreateFunction(RET,NAME,PARAM,CODE) struct Lambda##NAME { static RET apply PARAM CODE}; RET (*NAME)PARAM= Lambda##NAME::apply;

#endif

