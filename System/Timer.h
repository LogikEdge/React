#ifndef _LogikEdge_React_Timer_h
#define _LogikEdge_React_Timer_h

#include "../Targets/IReact.h"

namespace LogikEdge { namespace React {

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

	    static Milliseconds currentTime()               { return IReact::getMilliseconds(); }

	private:
	    Milliseconds myElapsedTime;
	};

}}

#endif


