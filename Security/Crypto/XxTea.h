#ifndef _LogikEdge_Seal_XxTea_h
#define _LogikEdge_Seal_XxTea_h

#include <stdint.h>

namespace LogikEdge { namespace Seal {

    // ======================================================================
    /// XxTea implements the _Corrected Block TEA_ encryption / decryption
    /// algorithm.
    ///
    /// The xxtea cipher is extremely small and requires no additional RAM
    /// and is therefore well suited for embedded system.
    ///
    /// Note that xxtea does suffer collision and is vulnerable to chosen
    /// plain-text attacks that requires a total of time*memory complexity
    /// 2^96.
    ///
    /// Note: xxtea is not commutative.  That is encoding with key1 then
    /// key2 does not give the same result as encoding with key2 followed
    /// by key1.
    struct XxTea {

        // ======================================================================
        /// Encodes an array using the _Correct Block TEA_ algorithm.
        ///
        /// @param array The array to be encoded (in place).
        /// @param arraySize Number of elements in the array.
        /// @param key The 128 bits key used by the encoding.
        /// @return The array is encoded in place.
        ///
        static void encode(uint32_t *array, const unsigned arraySize, const uint32_t key[4]);

        // ======================================================================
        /// Decodes an array using the _Correct Block TEA_ algorithm.
        ///
        /// @param array The array to be decoded (in place).
        /// @param arraySize Number of elements in the array.
        /// @param key The 128 bits key used by the encoding.
        /// @return The array is decoded in place.
        ///
        static void decode(uint32_t *array, const unsigned arraySize, const uint32_t key[4]);
    };

}}

#endif
