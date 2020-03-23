#pragma once

class FPC1020
{
public:
    void init();

    void reset();

    uint16_t hardware_id();
};