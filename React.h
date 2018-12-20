#ifndef React_h
#define React_h

// =======================================================================
/// Master React include file.
///
/// This can be used to include all of React include files with a single
/// include statement,
///
#include "sources/List.h"
#include "sources/Queue.h"
#include "sources/PriorityQueue.h"
#include "sources/IAction.h"
#include "sources/Dispatcher.h"
#include "sources/ITarget.h"
#include "sources/Timer.h"
#include "sources/Sll.h"
#include "sources/StreamBuf.h"

// =======================================================================
/// Default to using the React namespace.
using namespace React;


// =======================================================================
/// Global Definitions
///
/// This section declares the public interface of React.  All functionality
/// of React should be declared in this module only.
///
namespace React {
    /// Initialize the React kernel.
    void init();
    /// Run the React kernel
    void runOnce();
}

#endif
