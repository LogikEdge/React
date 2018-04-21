#ifndef _LogikEdge_Seal_Timer_h
#define _LogikEdge_Seal_Timer_h

#include "../Targets/ISeal.h"

namespace LogikEdge { namespace Seal {

	typedef long	Milliseconds;

	class Timer {
	public:
	    typedef void    Base;
	    typedef Timer   Type;

	    Timer(Milliseconds delay= 0)                    { restart(delay); }

	    void         restart(Milliseconds delay)        { myElapsedTime= currentTime() + delay; }
	    void         restartNoDrift(Milliseconds delay) { myElapsedTime+= delay; }
	    long         remainingTime() const           	{ return myElapsedTime-currentTime(); }
	    bool         isElapsed() const               	{ return remainingTime() <= 0; }
        Milliseconds elapsedTime() const                { return myElapsedTime; }

	    static Milliseconds currentTime()               { return ISeal::getMilliseconds(); }

	private:
	    Milliseconds myElapsedTime;
	};

}}

#endif


