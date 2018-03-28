#include "Execution/Scheduler.h"

// ==========================================================================
// For the Arduino sketch environment, only the top-level
// source file are included.  Therefore, we need to include
// all other sources to they are compiled.
#if defined(ARDUINO)
#include "Targets/Arduino/ISeal.cpp"
#include "Security/Crypto/src/XxTea.cpp"
#include "Execution/src/Scheduler.cpp"
#include "Execution/src/LowPowerMgr.cpp"
#endif


// ==========================================================================
/// Implementation of the public interface of Seal.
///
namespace LogikEdge { namespace Seal {
    /// Initializes the Seal framework
    void init() {}
    /// Runs the Seal framework
    void run()  { Scheduler::getInstance().run(); }

    void wakeupEvent(IProcess& process)
        { Scheduler::getInstance().wakeupEvent(process); }
    void wakeupAfterDelay(ITimedProcess& process, Milliseconds delay)
        { Scheduler::getInstance().wakeupAfterDelay(process, delay); }
    void wakeupPeriodic(IPeriodicProcess& process, Milliseconds period)
        { Scheduler::getInstance().wakeupPeriodic(process, period); }
    void wakeupContinuous(IProcess& process)
        { Scheduler::getInstance().wakeupContinuous(process); }
}}

// ==========================================================================
/// ARDUINO COMPATIBLE EXECUTION ENVIRONMENT
// ==========================================================================

// --------------------------------------------------------------------------
/// Setup the system.
///
/// Setup the Seal framework and give control to the application setup
/// function.
void setup() {
    LogikEdge::Seal::init();
    extern void setupApp();
    setupApp();
}

// --------------------------------------------------------------------------
/// Run the application.
void loop() {
    LogikEdge::Seal::run();
}

// ==========================================================================
/// SYSTEM EXECUTION ENVIRONMENT
// ==========================================================================

// --------------------------------------------------------------------------
/// Emulate the Arduino execution environment for other platform.
#if !defined(ARDUINO)
int main() {
    // -- Setup the Seal framework & application. --
    setup();
    // -- Contiuously run the application until an exit request is seen. --
    while(true) {
        try {
            loop();
        }
        catch(...) {}
    }
    return 0;
}
#endif
