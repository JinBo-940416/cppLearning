#include "utils.h"

std::size_t raise_to_2_powers(std::size_t v)
{
    if (0 == (v & (v - 1))) {
        return v; // size_min is a power of 2.
    }
    // size_min definitly has a highest bit of 1.
    v |= v >> 1; // highest bit index 0 set index 1 to 1.
    v |= v >> 2; // highest index 2,3 are set to 1 by index 0, 1
    v |= v >> 4; // highest index 4..7 are set to 1 by index 0..3
    v |= v >> 8; // highest index 8..16 are set to 1 by index 0..7
    v |= v >> 16; // highest index 0..15 are set to 1 by index 16..31
    v++;  // roll over so that highest bit index 0 is brought forward by 1 bit. Eg, 0b 0000 1111 --> 0b 0001 0000

    return v;
}

