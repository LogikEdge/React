#ifndef _LogikEdge_React_TypeInfo_h
#define _LogikEdge_React_TypeInfo_h


namespace LogikEdge { namespace React {

/// Builds the global TypeInfo descriptor for the given type.
#define MakeBaselessTypeInfo(TYPE) \
  const TypeInfo g##TYPE##TypeInfo= TypeInfo(#TYPE, 0 );
#define MakeTypeInfo(TYPE,BASE) \
  const TypeInfo g##TYPE##TypeInfo= TypeInfo(#TYPE, &g##BASE##TypeInfo);

/// Gets the TypeInfo descriptor from the type name.
#define toTypeInfo(TYPE)    g##TYPE##TypeInfo

    // ======================================================================
    /// The TypeInfo descriptor is used to statically or dynamically extract
    /// information pertaining the type it represents.
    class TypeInfo {
        const char*     myTypeName;
        const TypeInfo* myBase;

    public:
        TypeInfo(const char* theName, const TypeInfo* theBase) {
            myTypeName= theName;
            myBase= theBase;
        }
        bool operator==(const TypeInfo& theOther) const     { return this == &theOther; }
        bool operator !=(const TypeInfo& theOther) const    { return !operator==(theOther); }
        bool isA(const TypeInfo& theOther) const {
            if(*this == theOther) return true;
            return isDerivedFrom(theOther);
        }
        bool isDerivedFrom(const TypeInfo& theOther) const {
            if(myBase == 0) return false;
            if(*myBase == theOther) return true;
            return myBase->isDerivedFrom(theOther);
        }
        bool isBaseOf(const TypeInfo& theOther) const {
            return theOther.isDerivedFrom(*this);
        }

        /// Returns the type name.
        const char* const name() const { return myTypeName; }
    };

}}

#endif
