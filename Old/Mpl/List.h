#ifndef _LogikEdge_Mpl_List_h
#define _LogikEdge_Mpl_List_h

namespace LogikEdge { namespace Mpl {
	
	template <typename ElementType, typename NextType>
	struct List {
	  typedef ElementType Type;
	  typedef NextType    Next;
	};

	struct ListEnd {};

	template <typename Element>
	struct IsListEnd {
	  static const bool value= false;
	};
	template <>
	struct IsListEnd<ListEnd> {
	  static const bool value= true;
	};
}}

#endif
