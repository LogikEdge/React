#ifndef _LogikEdge_React_Mpl_IsPrimitive_h
#define _LogikEdge_React_Mpl_IsPrimitive_h

namespace LogikEdge { namespace Mpl {

	// =========================================================================
	/// Determines if the given type is a compiler primitive.
	template <typename T>
	struct IsPrimitive {
		static const bool value= false;
	};
	template <>
	struct IsPrimitive<bool> {
		static const bool value= true;
	};
	template <>
	struct IsPrimitive<signed char> {
		static const bool value= true;
	};
	template <>
	struct IsPrimitive<unsigned char> {
		static const bool value= true;
	};
	template <>
	struct IsPrimitive<short> {
		static const bool value= true;
	};
	template <>
	struct IsPrimitive<unsigned short> {
		static const bool value= true;
	};
	template <>
	struct IsPrimitive<int> {
		static const bool value= true;
	};
	template <>
	struct IsPrimitive<unsigned> {
		static const bool value= true;
	};
	template <>
	struct IsPrimitive<long> {
		static const bool value= true;
	};
	template <>
	struct IsPrimitive<unsigned long> {
		static const bool value= true;
	};
	template <>
	struct IsPrimitive<long long> {
		static const bool value= true;
	};
	template <>
	struct IsPrimitive<unsigned long long> {
		static const bool value= true;
	};
	template <>
	struct IsPrimitive<float> {
		static const bool value= true;
	};
	template <>
	struct IsPrimitive<double> {
		static const bool value= true;
	};
}}

#endif
