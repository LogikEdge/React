#ifndef LogikEdge_React_Timer_h
#define LogikEdge_React_Timer_h

#include "ITarget.h"

namespace LogikEdge { namespace React {

    typedef long Millisecond;   //< Type for millisecond units.

    // ==============================================================================
    /// The timer is used to determine the amount of time that remains until a given
    /// delay (elapse time) is reached.  The timer unit of time is the milliseconds.
    ///
    /// The timer calculates the elapse time from the given delay and the system
    /// time as follows:
    ///     elapseTime= currentTime + delay
    ///
    /// The remaining time is computed by the difference between the elaspeTime
    /// and the current time.  A positive remaining time means the delay as not
    /// been reached yet.  A negative value means that the delay has elapsed
    /// by the negative amount.
    ///
    /// NOTE: Since the remaining time is computed as a difference using
    /// 2s complement aritmitic, the wrap around of the system timer does
    /// not create numeric issues.
    struct Timer {

        // -------------------------------------------------------------------------
        /// Builds a timer and start it if a delay is given.
        Timer(Millisecond delay= -1) {
            stop();
            if(delay > 0) {
                start(delay);
            }
        }

        // -------------------------------------------------------------------------
        /// Returns the number of miliseconds that has passed.
        static Millisecond   getMilliseconds() {
            return ITarget::getMilliseconds();
        }

        // -------------------------------------------------------------------------
        /// Sets the timer elapse time with the given delay.
        void start(Millisecond delay) {
            elapseTime= getMilliseconds() + delay;
            isStarted= true;
        }

        // -------------------------------------------------------------------------
        /// Restarts the timer with a delay based on the previous elapse time.
        void restartNoDrift(Millisecond delay) {
            elapseTime+= delay;
            isStarted= true;
        }

        // -------------------------------------------------------------------------
        /// Stops the timer.
        void stop() {
            isStarted= false;
        }

        // -------------------------------------------------------------------------
        /// Returns the remainig time of the timer.
        /// @return The remaining time until the delay elapses.  A positive value
        ///         implies that the timer has not elapsed and the negative value
        ///         implies that the timer has elapsed for that period.
        Millisecond getRemainingTime() const {
            return isStarted ? elapseTime - getMilliseconds() : 0;
        }

        // -------------------------------------------------------------------------
        /// Returns the elapse time of the timer.
        /// @return The elapse time of the timer.  Zero (0) is returned if the
        ///         timer is not active.
        Millisecond getElapseTime() const {
            return isStarted ? elapseTime : 0;
        }

        // -------------------------------------------------------------------------
        /// Deterimines if the timer has elapsed.
        /// @return true if timer has elapsed. false otherwise.
        bool isElapsed() const {
            return isStarted && getRemainingTime() <= 0;
        }

        // -------------------------------------------------------------------------
        /// Determines if the timer is active.
        /// @return true if active. false otherwise.
        bool isActive() const {
            return isStarted;
        }

    private:
        Millisecond  elapseTime;     ///< The time at which the timer will elaspe.
        bool         isStarted : 1;  ///< Timer start / stop state.
    };

}}

#endif
