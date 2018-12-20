// ==========================================================================
// For the Arduino sketch environment, only the top-level
// source file are included.  Therefore, we need to include
// all other sources for them to be compiled.
#if defined(ARDUINO)
#include "sources/List.cpp"
#include "sources/Queue.cpp"
#include "sources/PriorityQueue.cpp"
#include "sources/Dispatcher.cpp"
#include "sources/ITarget/Arduino.cpp"
#endif


// ==========================================================================
/// Implementation of the public interface of React.
///
namespace React {
    /// Initializes the React framework
    void init() {}
    void runOnce() {
        React::Dispatcher::getInstance().runOnce();
    }
}

// ==========================================================================
/// SYSTEM EXECUTION ENVIRONMENT
// ==========================================================================

// --------------------------------------------------------------------------
/// Emulate the Arduino execution environment for other platform.
#if !defined(ARDUINO)
int main() {
    // -- Setup the React framework & application. --
    React::init();
    // -- Contiuously run the application until an exit request is seen. --
    while(true) {
        try {
            React::runOnce();
        }
        catch(...) {}
    }
    return 0;
}
#endif
