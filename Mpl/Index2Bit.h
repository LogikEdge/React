#ifndef _LogikEdge_Mpl_Index2Bit_h
#define _LogikEdge_Mpl_Index2Bit_h

namespace LogikEdge { namespace Mpl {
	
	// =========================================================================
	/// Converts a bit index to its bit representation.
	///
	/// @param kBitIndex The bit index
	/// @param T         The type used for the bit representation.
	///
	/// @usage bitValue= Index2Bit<kBitIndex>::value;
	/// 
	template <int kBitIndex, typename T= unsigned>
	struct Index2Bit {
		static const T value= (1 << kBitIndex);
	};
	
}}

#endif
