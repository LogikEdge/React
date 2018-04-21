// ==========================================================================
// For the Arduino sketch environment, only the top-level
// source file are included.  Therefore, we need to include
// all other sources to they are compiled.
#if defined(ARDUINO)
#include "sources/Cdll.cpp"
#include "sources/CdllQueue.cpp"
#include "sources/CdllPriorityQueue.cpp"
#include "sources/Dispatcher.cpp"
#endif


// ==========================================================================
/// Implementation of the public interface of React.
///
namespace LogikEdge { namespace React {
    /// Initializes the React framework
    void init() {}
    void runOnce() {
        LogikEdge::React::Dispatcher::getInstance().runOnce();
    }
}}

// ==========================================================================
/// SYSTEM EXECUTION ENVIRONMENT
// ==========================================================================

// --------------------------------------------------------------------------
/// Emulate the Arduino execution environment for other platform.
#if !defined(ARDUINO)
int main() {
    // -- Setup the React framework & application. --
    LogikEdge::React::init();
    // -- Contiuously run the application until an exit request is seen. --
    while(true) {
        try {
            LogikEdge::React::runOnce();
        }
        catch(...) {}
    }
    return 0;
}
#endif
