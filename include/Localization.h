#pragma once

namespace PW21Z_OP
{
    struct Localization
    {
        const double _x, _y, _z;
        Localization(double x, double y, double z) : _x{x}, _y{y}, _z{z} {}
    };
}