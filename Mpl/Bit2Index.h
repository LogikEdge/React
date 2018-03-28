#ifndef _LogikEdge_Mpl_Bit2Index_h
#define _LogikEdge_Mpl_Bit2Index_h

namespace LogikEdge { namespace Mpl {
	
	/// Bit2Index step reduction functionality.
	template <unsigned kBit0, unsigned kBits, unsigned kIndex, unsigned kIndexError>
	struct _Bit2Index {
		static const unsigned kShiftedBits= (kBits >> 1);
		static const unsigned value= _Bit2Index<(kShiftedBits & 1), kShiftedBits, kIndex+1, kIndexError>::value;
	};
	
	/// Bit2Index no bit set error detection. 
	template <unsigned kIndex, unsigned kIndexError>
	struct _Bit2Index<0,0, kIndex, kIndexError> {
		static const unsigned value= kIndexError;
	};
	
	/// Bit2Index reduction termination when a set (1) bit is found.
	template <unsigned kBits, unsigned kIndex, unsigned kIndexError>
	struct _Bit2Index<1, kBits, kIndex, kIndexError> {
		static const unsigned value= kIndex;
	};


	// =========================================================================
	/// Converts a bit representation to a bit index.
	///
	/// @param kBits  The bit representation
	///
	/// @usage index= Bit2Index<kBitValue>::value;
	/// 
	template <unsigned kBits, unsigned kIndexError= 0>
	struct Bit2Index {
		static const unsigned value= _Bit2Index<(kBits & 1), kBits, 0, kIndexError>::value;
	};
}}

#endif
