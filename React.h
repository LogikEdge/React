#ifndef _LogikEdge_React_h
#define _LogikEdge_React_h

// =======================================================================
/// Master React include file.
///
/// This can be used to include all of React include files with a single
/// include statement,
///
#include "sources/Cdll.h"
#include "sources/CdllQueue.h"
#include "sources/IAction.h"
#include "sources/Dispatcher.h"

// =======================================================================
/// Default to using the React namespace.
using namespace LogikEdge;
using namespace LogikEdge::React;


// =======================================================================
/// Global Definitions
///
/// This section declares the public interface of React.  All functionality
/// of React should be declared in this module only.
///
namespace LogikEdge { namespace React {
    /// Initialize the React kernel.
    void init();
    /// Run the React kernel
    void runOnce();
}}

#endif
