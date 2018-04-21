#ifndef _LogikEdge_Seal_IProcess_h
#define _LogikEdge_Seal_IProcess_h

#include "../Containers/List.h"

namespace LogikEdge { namespace Seal {
    // ========================================================================
    /// Seal process base class.
    ///
    /// All processes that are ran by the scheduler must override the doRun(...)
    /// function is this base class.
    struct IProcess : public ListElement {

        // ====================================================================
        /// Runs the process.
        ///
        /// @param p    Pointer to the parameters of the process.
        //
        void run()    { doRun(); }

    protected:
        /// Function to override to implement process functionality.
        virtual void doRun()= 0;

    };

}}

#endif
