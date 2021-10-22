#include "TrafficLane.h"

namespace PW21Z_OP
{
    void TrafficLane::add_TrafficParticipant(const TrafficParticipant &tp) { traffic_participants_container.emplace(tp._uid, tp); }
    void TrafficLane::add_TrafficParticipant(TrafficParticipant &&tp) { traffic_participants_container.emplace(tp._uid, std::move(tp)); }
    void TrafficLane::add_TrafficLaneTeleporter(const TrafficLaneTeleporter &tlt) { traffic_lane_teleporters_container.emplace(tlt._uid, tlt); }
    void TrafficLane::add_TrafficLaneTeleporter(TrafficLaneTeleporter &&tlt) { traffic_lane_teleporters_container.emplace(tlt._uid, std::move(tlt)); }
    void TrafficLane::add_TrafficSign(const TrafficSign &ts) { traffic_signs_container.emplace(ts._uid, ts); }
    void TrafficLane::add_TrafficSign(TrafficSign &&ts) { traffic_signs_container.emplace(ts._uid, std::move(ts)); }

    TrafficParticipant &TrafficLane::get_TrafficParticipant(const long long uid) { return traffic_participants_container.at(uid); }
    const TrafficParticipant &TrafficLane::get_TrafficParticipant(const long long uid) const { return traffic_participants_container.at(uid); }
    TrafficLaneTeleporter &TrafficLane::get_TrafficLaneTeleporter(const long long uid) { return traffic_lane_teleporters_container.at(uid); }
    const TrafficLaneTeleporter &TrafficLane::get_TrafficLaneTeleporter(const long long uid) const { return traffic_lane_teleporters_container.at(uid); }
    TrafficSign &TrafficLane::get_TrafficSign(const long long uid) { return traffic_signs_container.at(uid); }
    const TrafficSign &TrafficLane::get_TrafficSign(const long long uid) const { return traffic_signs_container.at(uid); }

    void TrafficLane::remove_TrafficParticipant(const long long uid) { traffic_participants_container.erase(uid); }
    void TrafficLane::remove_TrafficLaneTeleporter(const long long uid) { traffic_lane_teleporters_container.erase(uid); }
    void TrafficLane::remove_TrafficSign(const long long uid) { traffic_signs_container.erase(uid); }

    void TrafficLaneTeleporter::teleport_TrafficParticipant(const long long tp_uid)
    {
        _destination.add_TrafficParticipant(std::move(_origin.get_TrafficParticipant(tp_uid)));
        _origin.remove_TrafficParticipant(tp_uid);
    }
}