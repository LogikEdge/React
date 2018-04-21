#ifndef _LogikEdge_Seal_LowPowerMgr_h
#define _LogikEdge_Seal_LowPowerMgr_h

#include "IProcess.h"

namespace LogikEdge { namespace Seal {


// ==========================================================================
/// This process puts the CPU core to sleep when Seal as completed to run
/// all of its high-priority processes.
///
/// **Note:** The behaviour differs depending on the type of system Seal
/// runs on.  This process will:
/// - sleep its thread if Seal runs on an existing OS (eg, Linux, OSX, Windows);
/// -  suspend MCU core operation if Seal runs on bare metal hardware.
///
struct LowPowerMgr : public IProcess {
    // -- Returns the singleton instance of the low power manager. --
    static LowPowerMgr& getInstance() { return ourInstance; }

private:
    // -- Singleton instance. --
    static LowPowerMgr  ourInstance;

    // -- Suspends Seal execution until the next high-priority process. --
    void doRun();
};


}}

#endif
