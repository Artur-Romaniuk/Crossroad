#pragma once
#include <utility>
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
        TrafficLane(const TrafficLane &tl) = delete;            //no copy constructor, not sure if I need it
        TrafficLane &operator=(const TrafficLane &tl) = delete; //no copy operator

        void add_TrafficParticipant(const TrafficParticipant &tp) { traffic_participants_container.emplace(tp._uid, tp); }
        void add_TrafficParticipant(TrafficParticipant &&tp) { traffic_participants_container.emplace(tp._uid, std::move(tp)); }
        void add_TrafficLaneTeleporter(const TrafficLaneTeleporter &tlt) { traffic_lane_teleporters_container.emplace(tlt._uid, tlt); }
        void add_TrafficLaneTeleporter(TrafficLaneTeleporter &&tlt) { traffic_lane_teleporters_container.emplace(tlt._uid, std::move(tlt)); }
        void add_TrafficSign(const TrafficSign &ts) { traffic_signs_container.emplace(ts._uid, ts); }
        void add_TrafficSign(TrafficSign &&ts) { traffic_signs_container.emplace(ts._uid, std::move(ts)); }
        TrafficParticipant &get_TrafficParticipant(long long uid) { return traffic_participants_container.at(uid); }
        const TrafficParticipant &get_TrafficParticipant(long long uid) const { return traffic_participants_container.at(uid); }
        TrafficLaneTeleporter &get_TrafficLaneTeleporter(long long uid) { return traffic_lane_teleporters_container.at(uid); }
        const TrafficLaneTeleporter &get_TrafficLaneTeleporter(long long uid) const { return traffic_lane_teleporters_container.at(uid); }
        TrafficSign &get_TrafficSign(long long uid) { return traffic_signs_container.at(uid); }
        const TrafficSign &get_TrafficSign(long long uid) const { return traffic_signs_container.at(uid); }
    };

    class TrafficLaneWithLocalization : public TrafficLane
    {
    public:
        const PW21Z_OP::Localization _localization;
        TrafficLaneWithLocalization() = delete;
        TrafficLaneWithLocalization(double length, const Localization &localization) : _localization{localization}, TrafficLane(length) {}
        TrafficLaneWithLocalization(double length, double x, double y, double z) : _localization{x, y, z}, TrafficLane(length) {}
    };
}