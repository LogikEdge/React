#ifndef _LogikEdge_React_LowPowerMgr_h
#define _LogikEdge_React_LowPowerMgr_h

#include "IProcess.h"

namespace LogikEdge { namespace React {


// ==========================================================================
/// This process puts the CPU core to sleep when React as completed to run
/// all of its high-priority processes.
///
/// **Note:** The behaviour differs depending on the type of system React
/// runs on.  This process will:
/// - sleep its thread if React runs on an existing OS (eg, Linux, OSX, Windows);
/// -  suspend MCU core operation if React runs on bare metal hardware.
///
struct LowPowerMgr : public IProcess {
    // -- Returns the singleton instance of the low power manager. --
    static LowPowerMgr& getInstance() { return ourInstance; }

private:
    // -- Singleton instance. --
    static LowPowerMgr  ourInstance;

    // -- Suspends React execution until the next high-priority process. --
    void doRun();
};


}}

#endif
