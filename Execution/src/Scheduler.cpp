#include "../Scheduler.h"
#include "../LowPowerMgr.h"

namespace LogikEdge { namespace Seal {
    /// The system scheduler
    Scheduler   Scheduler::ourInstance;

// --------------------------------------------------------------------------
/// Builds the scheduler and starts the low-power managemewnt process.
Scheduler::Scheduler()
: myEventQueue(), myTimedQueue(), myBackgroundQueue()
{
    wakeupContinuous(LowPowerMgr::getInstance());
}

// --------------------------------------------------------------------------
void Scheduler::wakeupEvent(IProcess& p) {
    myEventQueue.addAtBottom(p);
}
// --------------------------------------------------------------------------
void Scheduler::wakeupAfterDelay(ITimedProcess& p, Milliseconds theDelay) {
    p.startTimer(theDelay);
    myTimedQueue.addElement(p);
}
// --------------------------------------------------------------------------
void Scheduler::wakeupPeriodic(IPeriodicProcess& p, Milliseconds theInterval) {
    p.setInterval(theInterval);
    p.startTimer();
    myTimedQueue.addElement(p);
}
// --------------------------------------------------------------------------
void Scheduler::wakeupContinuous(IProcess& p) {
    myBackgroundQueue.addAtBottom(p);
}

// --------------------------------------------------------------------------
/// This function repeatively executes the processes that are queued for
/// execution.
///
/// The function will exist if a shutdown was requested or their is
/// nothing left in the queue to be ran.
///
void Scheduler::run() {
    // -- Run all processes until shutdown is requested.
    while(!isShutdownRequested()) {
        // -- Verify Event processes --
        IProcess* nextToRun= myEventQueue.getFromTop();
        if(nextToRun != 0) {
            nextToRun->run();
            continue;
        }
        // -- Verify timed processes --
        ITimedProcess* timedProcess= myTimedQueue.peakAtTop();
        if(timedProcess != 0 && timedProcess->isReadyToRun()) {
            myTimedQueue.getFromTop();
            timedProcess->run();
            if(timedProcess->isPeriodic()) {
                ((IPeriodicProcess*)timedProcess)->startTimer();
                myTimedQueue.addElement(*timedProcess);
            }
            continue;
        }
        // -- Verify background processes --
        nextToRun= myBackgroundQueue.getFromTop();
        if(nextToRun == 0) return;
        myBackgroundQueue.addAtBottom(*nextToRun);
        nextToRun->run();
    }
}

// --------------------------------------------------------------------------
/// Returns 'true' if a scheduler shutdown has been requested. 'false' is
/// returned otherwise.
bool Scheduler::isShutdownRequested() const {
    return false;
}

// --------------------------------------------------------------------------
/// Returns the minimum delay for the next delayed or periodic process to
/// run.
///
/// @param maxDelay The maximum to delay is allowed to be.
/// @return Minimum delay of the next periodic or delayed process.
///
Milliseconds Scheduler::getDelayTillNextTimedProcess(Milliseconds maxDelay) {
    // -- Start with the maximum delay. --
    Milliseconds delay= maxDelay;
    // -- Consider the next timed process. --
    ITimedProcess* timedProcess= myTimedQueue.peakAtTop();
    if(timedProcess != 0) {
        Milliseconds remainingTime= timedProcess->remainingTime();
        if(remainingTime < delay) {
            delay= remainingTime;
        }
    }
    // -- Don't allow a negative delay. --
    if(delay < 0) delay= 0;
    return delay;
}

}}
