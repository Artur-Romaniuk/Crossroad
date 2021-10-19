#pragma once
#include "ID.h"
#include "Localization.h"

namespace PW21Z_OP
{
    class TrafficSign : public ID
    {
    public:
        bool _is_active;
        explicit TrafficSign(bool is_active) : _is_active{is_active} {}
        TrafficSign() : TrafficSign(true) {}
    };

    class TrafficSingWithLocalization : public TrafficSign
    {
        const PW21Z_OP::Localization _localization;
        TrafficSingWithLocalization(const PW21Z_OP::Localization &localization, bool is_active) : _localization{localization}, TrafficSign(is_active) {}
        explicit TrafficSingWithLocalization(const PW21Z_OP::Localization &localization) : TrafficSingWithLocalization(localization, true) {}
        TrafficSingWithLocalization(double x, double y, double z, bool is_active) : _localization{x, y, z}, TrafficSign(is_active) {}
        TrafficSingWithLocalization(double x, double y, double z) : TrafficSingWithLocalization(x, y, z, true) {}
    };
}