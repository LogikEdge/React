#ifndef _LogikEdge_React_IValidity_h
#define _LogikEdge_React_IValidity_h

namespace LogikEdge { namespace React {
	
	// =========================================================================
	/// Defines the concept of object validity.
    ///
    /// @note   If not overriden, the object is consider valid.
    ///
	struct IValidity {		
		typedef void	    Base;
		typedef IValidity   Type;
		
		virtual bool isValid() const    { return true; }
	};

}}

#endif
