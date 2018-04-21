#ifndef _LogikEdge_Mpl_RemoveConst_h
#define _LogikEdge_Mpl_RemoveConst_h

namespace LogikEdge { namespace Mpl {
	// =========================================================================
	/// Removes the _const_ qualifier of the given type.
	///
	/// @param T The type from which to remove the _const_ qualifier.
	/// @return RemoveConst<T>::Type is the resulting type. 
	template<typename T>
	struct RemoveConst {
		typedef T	Type;
	};
	template <typename T>
	struct RemoveConst<const T> {
		typedef T	Type;
	};
}}

#endif
