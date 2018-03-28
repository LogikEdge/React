#include "../LowPowerMgr.h"
#include "../../Targets/IReact.h"
#include "../Scheduler.h"

namespace LogikEdge { namespace React {

// -- Declare the low power manager singleton.--
LowPowerMgr LowPowerMgr::ourInstance;

// --------------------------------------------------------------------------
/// Suspends React execution until the next high-priority process.
void LowPowerMgr::doRun() {
    Milliseconds sleepTime= Scheduler::getInstance().getDelayTillNextTimedProcess(1000);
    IReact::sleep(sleepTime);
}

}}
