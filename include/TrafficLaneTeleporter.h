#pragma once
#include "ID.h"
#include "TrafficLane.fwd.h"

namespace PW21Z_OP
{
    class TrafficLaneTeleporter : public ID
    {
    public:
        TrafficLane &_origin;
        TrafficLane &_destination;
        bool _is_active;
        TrafficLaneTeleporter() = delete;
        TrafficLaneTeleporter(TrafficLane &origin, TrafficLane &destination, bool is_active)
            : _origin{origin}, _destination{destination}, _is_active{is_active} {}
        TrafficLaneTeleporter(TrafficLane &origin, TrafficLane &destination) : TrafficLaneTeleporter(origin, destination, true) {}
        void teleport_TrafficParticipant(long long tp_uid);
    };
}