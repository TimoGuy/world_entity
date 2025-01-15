#pragma once

#include <cinttypes>


struct GUID
{
    uint32_t d1;
    uint16_t d2;
    uint16_t d3;
    uint8_t  d4[8];

    static GUID generate();

private:
    GUID() = default;
};
