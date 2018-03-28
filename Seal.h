#ifndef _LogikEdge_Seal_h
#define _LogikEdge_Seal_h

// =======================================================================
/// Master Seal include file.
///
/// This can be used to include all of Seal include files with a single
/// include statement,
///
#if defined(ARDUINO)
#include "std/all.h"
#endif
#include "CppUtilities/All.h"
#include "Mpl/All.h"
#include "Targets/All.h"
#include "System/All.h"
#include "Containers/All.h"
#include "Execution/All.h"
#include "Security/All.h"

// =======================================================================
/// Default to using the Seal namespace.
using namespace LogikEdge;
using namespace LogikEdge::Seal;


// =======================================================================
/// Global Definitions
///
/// This section declares the public interface of Seal.  All functionality
/// of Seal should be declared in this module only.
///
namespace LogikEdge { namespace Seal {
        /// Initialize the Seal kernel.
        void init();
        /// Run the Seal kernel
        void run();

        /// Wakes up an event process
        void wakeupEvent(IProcess&);
        /// Wakes up a process for later execution
        void wakeupAfterDelay(ITimedProcess&, Milliseconds);
        /// Wakes up a periodic process
        void wakeupPeriodic(IPeriodicProcess&, Milliseconds);
        /// Wakes up a process for execution when the system is idle
        void wakeupContinuous(IProcess&);
}}

#endif
