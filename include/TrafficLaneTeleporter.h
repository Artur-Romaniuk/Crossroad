#pragma once
#include "ID.h"
#include "TrafficLane.fwd.h"

namespace PW21Z_OP
{
    class TrafficLaneTeleporter : public ID
    {
    public:
        const TrafficLane &_origin;
        const TrafficLane &_destination;
        bool _is_active;
        TrafficLaneTeleporter(const TrafficLane &origin, const TrafficLane &destination, bool is_active)
            : _origin{origin}, _destination{destination}, _is_active{is_active} {}
        TrafficLaneTeleporter(const TrafficLane &origin, const TrafficLane &destination) : TrafficLaneTeleporter(origin, destination, true) {}
    };
}