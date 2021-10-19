#pragma once
#include <map>
#include <vector>
#include "ID.h"
#include "Localization.h"
#include "TrafficParticipant.h"
#include "TrafficSign.h"
#include "TrafficLaneTeleporter.h"

namespace PW21Z_OP
{
    class TrafficLane : public ID
    {
    public:
        std::map<long long, TrafficParticipant> traffic_participants_container;
        std::map<long long, TrafficSign> traffic_signs_container;
        std::map<long long, TrafficLaneTeleporter> traffic_lane_teleporters_container;
        const double _length;
        TrafficLane() = delete;
        explicit TrafficLane(double length) : _length{length} {}
    };

    class TrafficLaneWithLocalization : public TrafficLane
    {
    public:
        const PW21Z_OP::Localization _localization;
        TrafficLaneWithLocalization() = delete;
        TrafficLaneWithLocalization(double length, const PW21Z_OP::Localization &localization) : _localization{localization}, TrafficLane(length) {}
        TrafficLaneWithLocalization(double length, double x, double y, double z) : _localization{x, y, z}, TrafficLane(length) {}
    };
}