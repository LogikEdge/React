#ifndef _LogikEdge_React_Property_h
#define _LogikEdge_React_Property_h

// ==========================================================================
/// Helpers to define class properties.
///
/// @param TYPE The type of the property.
/// @param NAME The name of the property.  The name must formatted using
///             upper camel case.
/// @param ACCESSORS The type of accessor that should be generated.
///                  - Private: no accessor
///                  - ReadOnly: only the get accessor is generated.
///                  - ReadWite: get and set accessors are generated.
#define Property(TYPE, NAME, ACCESSORS) \
private: \
	TYPE my##NAME;\
Property_##ACCESSORS(TYPE, NAME)
			
#define Property_Private(TYPE, NAME) \
public:
			
#define Property_ReadOnly(TYPE ,NAME) \
public: \
	inline TYPE get##NAME() { return my##NAME; }
	
#define Property_ReadWrite(TYPE, NAME) \
public: \
	inline void set#NAME(TYPE value) { my##NAME= value; } \
	inline TYPE get##NAME()		     { return my##NAME; }

#endif

