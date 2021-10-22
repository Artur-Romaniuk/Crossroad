#pragma once
#include <utility>
#include <map>
#include <vector>
#include "ID.h"
#include "Localization.h"
#include "TrafficParticipant.h"
#include "TrafficSign.h"

namespace PW21Z_OP
{
    class TrafficLane;
    class TrafficLaneWithLocalization;
    class TrafficLaneTeleporter;

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

        void add_TrafficParticipant(const TrafficParticipant &tp);
        void add_TrafficParticipant(TrafficParticipant &&tp);
        void add_TrafficLaneTeleporter(const TrafficLaneTeleporter &tlt);
        void add_TrafficLaneTeleporter(TrafficLaneTeleporter &&tlt);
        void add_TrafficSign(const TrafficSign &ts);
        void add_TrafficSign(TrafficSign &&ts);

        TrafficParticipant &get_TrafficParticipant(const long long uid);
        const TrafficParticipant &get_TrafficParticipant(const long long uid) const;
        TrafficLaneTeleporter &get_TrafficLaneTeleporter(const long long uid);
        const TrafficLaneTeleporter &get_TrafficLaneTeleporter(const long long uid) const;
        TrafficSign &get_TrafficSign(const long long uid);
        const TrafficSign &get_TrafficSign(const long long uid) const;

        void remove_TrafficParticipant(const long long uid);
        void remove_TrafficLaneTeleporter(const long long uid);
        void remove_TrafficSign(const long long uid);
    };

    class TrafficLaneWithLocalization : public TrafficLane
    {
    public:
        const Localization _localization;
        TrafficLaneWithLocalization() = delete;
        TrafficLaneWithLocalization(double length, const Localization &localization) : _localization{localization}, TrafficLane(length) {}
        TrafficLaneWithLocalization(double length, double x, double y, double z) : _localization{x, y, z}, TrafficLane(length) {}
    };

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
        void teleport_TrafficParticipant(const long long tp_uid);
    };
}