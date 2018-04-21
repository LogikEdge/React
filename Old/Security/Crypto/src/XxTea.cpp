#include "../XxTea.h"

#define DELTA 0x9e3779b9
#define MX (((z>>5^y<<2) + (y>>3^z<<4)) ^ ((sum^y) + (key[(p&3)^e] ^ z)))

namespace LogikEdge { namespace React {

    // ======================================================================
    /// Utility function used to compute the core XXTEA algorithm.
    static uint32_t mx(uint32_t y, uint32_t z, uint32_t sum, unsigned e, unsigned p, const uint32_t key[4]) {
        return MX;
    }

    // ======================================================================
    /// Encodes an array using the _Correct Block TEA_ algorithm.
    ///
    /// @param array The array to be encoded (in place).
    /// @param arraySize Number of elements in the array.
    /// @param key The 128 bits key used by the encoding.
    /// @return The array is encoded in place.
    ///
    void XxTea::encode(uint32_t *array, const unsigned arraySize, const uint32_t key[4]) {
        uint32_t y, z, sum;
        unsigned p, rounds, e;
        if(arraySize == 0) return;
        unsigned lastIdx= arraySize-1;

        rounds = 6 + 52/arraySize;
        sum = 0;
        z = array[lastIdx];
        do {
            sum += DELTA;
            e = (sum >> 2) & 3;
            for (p= 0; p < lastIdx; ++p) {
                y = array[p+1];
                z = array[p] += mx(y, z, sum, e, p, key);
            }
            y = array[0];
            z = array[lastIdx] += mx(y, z, sum, e, p, key);
        } while (--rounds);
    }

    // ======================================================================
    /// Decodes an array using the _Correct Block TEA_ algorithm.
    ///
    /// @param array The array to be decoded (in place).
    /// @param arraySize Number of elements in the array.
    /// @param key The 128 bits key used by the encoding.
    /// @return The array is decoded in place.
    ///
    void XxTea::decode(uint32_t *array, const unsigned arraySize, const uint32_t key[4]) {
        uint32_t y, z, sum;
        unsigned p, rounds, e;
        if (arraySize == 0) return;
        unsigned lastIdx= arraySize-1;

        rounds = 6 + 52/arraySize;
        sum = rounds*DELTA;
        y = array[0];
        do {
            e = (sum >> 2) & 3;
            for (p= lastIdx; p > 0; --p) {
                z = array[p-1];
                y = array[p] -= mx(y, z, sum, e, p, key);
            }
            z = array[lastIdx];
            y = array[0] -= mx(y, z, sum, e, p, key);
            sum -= DELTA;
        } while (--rounds);
    }

}}
