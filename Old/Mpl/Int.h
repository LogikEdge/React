#ifndef _LogikEdge_Mpl_Int_h
#define _LogikEdge_Mpl_Int_h

namespace LogikEdge { namespace Mpl {
	template <int N>
	struct Int {
	  typedef Int<N>    Type;
	  typedef Int<N+1>  NextType;
	  typedef Int<N-1>  PreviousType;
  
	  static const int  value= N;
	  static const int  nextValue= N+1;
	  static const int  previousValue= N-1;
	};	
}}

#endif
