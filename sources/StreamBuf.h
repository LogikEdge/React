#ifndef React_StreamBuf_h
#define React_StreamBuf_h

#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include "ITarget.h"

namespace React {

    struct StreamBufBase {
        // -------------------------------------------------------------------
        /// Builds a byte stream buffer using the suplied buffer as storage.
        ///
        /// @param buffer - The storage area for the stream buffer.
        /// @param size   - The size of the storage area.
        StreamBufBase(uint8_t* buffer, size_t size) {
            this->buffer     = buffer;
            this->bufferSize = size;
            rxCursor = txCursor = 0;
        }

        // -------------------------------------------------------------------
        /// Determines if the stream buffer is empty.
        ///
        /// @return - True if empty; false otherwise.
        bool isEmpty() const { return txCursor == rxCursor; }

        // -------------------------------------------------------------------
        size_t availableForRead() const {
            size_t avail = txCursor - rxCursor + bufferSize;
            return avail <= bufferSize ? avail : avail - bufferSize;
        }
        // -------------------------------------------------------------------
        size_t availableForWrite() const
        {
            size_t avail = rxCursor - txCursor + bufferSize -1;
            return avail <= bufferSize ? avail : avail - bufferSize;
        }
        // -------------------------------------------------------------------
        bool peek(uint8_t &c)
        {
            if (isEmpty()) return false;
            c= buffer[rxCursor];
            return true;
        }
        // -------------------------------------------------------------------
        size_t read(uint8_t* output, size_t size)
        {
            if(isEmpty()) return 0;
            ITarget::startCriticalSection();
            size_t toRead = min(size, availableForRead());

            addToRxCursor(toRead);
            ITarget::endCriticalSection();
            return true;
        }

    protected:
        void addToRxCursor(unsigned toAdd) { rxCursor = (rxCursor + toAdd) % bufferSize; }
        void addToTxCursor(unsigned toAdd) { txCursor = (txCursor + toAdd) % bufferSize; }

    protected:
        unsigned rxCursor;
        unsigned txCursor;
        uint8_t* buffer;
        size_t   bufferSize;
    };

    template <unsigned SIZE>
    struct StreamBuf : public StreamBufBase {
        StreamBuf() : StreamBufBase(buffer, SIZE) {}
    protected:
        uint8_t     buffer[SIZE];
    };
}

#endif