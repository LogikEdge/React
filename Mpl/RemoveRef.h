#ifndef _LogikEdge_Mpl_RemoveRef_h
#define _LogikEdge_Mpl_RemoveRef_h

namespace LogikEdge { namespace Mpl {
	// =========================================================================
	/// Removes the reference specifier of the given type.
	///
	/// @param T The type from which to remove the reference.
	/// @return RemoveConst<T>::Type is the resulting type. 
	template<typename T>
	struct RemoveRef {
		typedef T	Type;
	};
	template <typename T>
	struct RemoveRef<T&> {
		typedef T	Type;
	};
}}

#endif
