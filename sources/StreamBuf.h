#ifndef React_StreamBuf_h
#define React_StreamBuf_h

#include <stdint.h>
#include "ITarget.h"

namespace React {

    template <unsigned SIZE>
    struct StreamBuf {
        StreamBuf() { rxCursor = txCursor = 0; }

        bool isEmpty() const { return txCursor == rxCursor; }
        unsigned rxAvailable() const {
            return (txCursor - rxCursor + SIZE) % SIZE;
        }
        unsigned txAvailable() const {
            return (rxCursor - txCursor + SIZE -1) % SIZE;
        }
        bool pop(uint8_t& c) {
            if(isEmpty()) return false;
            ITarget::startCriticalSection();
            c= buffer[rxCursor];
            incRxCursor();
            ITarget::endCriticalSection();
            return true;
        }

    protected:
        void incRxCursor() { if(++rxCursor >= SIZE) rxCursor = 0; }
        void incTxCursor() { if(++txCursor >= SIZE) txCursor = 0; }

    protected:
        unsigned rxCursor;
        unsigned txCursor;
        uint8_t  buffer[SIZE];
    };

}

#endif