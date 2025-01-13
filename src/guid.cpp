#include "guid.h"

#include <random>


GUID GUID::generate()
{
    static thread_local std::mt19937 mt{ std::random_device{}() };
    static std::uniform_int_distribution<uint32_t> u32_dist;
    static std::uniform_int_distribution<uint16_t> u16_dist;

    GUID new_guid;
    new_guid.d1 = u32_dist(mt);
    new_guid.d2 = u16_dist(mt);
    new_guid.d3 = u16_dist(mt);
    for (size_t i = 0; i < 8; i++)
    {
        // @NOTE: u8 uniform int distribution not supported, so fall back to u32.
        new_guid.d4[i] = static_cast<uint8_t>(u32_dist(mt) % 256u);
    }
    return new_guid;
}
