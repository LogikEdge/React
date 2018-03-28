#ifndef _LogikEdge_Mpl_If_h
#define _LogikEdge_Mpl_If_h

namespace LogikEdge { namespace Mpl {
	
    // =====================================================================
    /// Implements the default Mpl::If that selects the _false_ type.
	///
	/// @param TrueType	 The type for when the _If_ evaluates to true.
	/// @param FalseType The type for when the _If_ evaluates to false.
	///
	template <bool, typename TrueType, typename FalseType>
	struct If {
	  typedef FalseType Type;
	};

    // =====================================================================
    /// Implements the _true_ version of the Mpl::If that selects the
    /// _true_ type.
	///
	/// @param TrueType	 The type for when the _If_ evaluates to true.
	/// @param FalseType The type for when the _If_ evaluates to false.
	///
	template <typename TrueType, typename FalseType>
	struct If<true, TrueType, FalseType> {
	  typedef TrueType  Type;
	};
	
}}

#endif
