#ifndef _LogikEdge_Seal_ISerializable_h
#define _LogikEdge_Seal_ISerializable_h

#include "../CppUtilities/Interface.h"

namespace LogikEdge { namespace Seal {

    // ======================================================================
    /// Define the serializable interface.
    interface ISerializable {
        virtual void serialize() const= 0;
        virtual void deserialize()= 0;
    };
    
}}

#endif
