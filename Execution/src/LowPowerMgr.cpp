#include "../LowPowerMgr.h"
#include "../../Targets/ISeal.h"
#include "../Scheduler.h"

namespace LogikEdge { namespace Seal {

// -- Declare the low power manager singleton.--
LowPowerMgr LowPowerMgr::ourInstance;

// --------------------------------------------------------------------------
/// Suspends Seal execution until the next high-priority process.
void LowPowerMgr::doRun() {
    Milliseconds sleepTime= Scheduler::getInstance().getDelayTillNextTimedProcess(1000);
    ISeal::sleep(sleepTime);
}

}}
