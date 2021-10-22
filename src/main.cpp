#include <iostream>
#include <utility>
#include "TrafficLane.h"
#include "TrafficParticipant.h"
#include "TrafficLaneTeleporter.h"

int main()
{
    PW21Z_OP::TrafficParticipant tp{};
    PW21Z_OP::TrafficParticipant tp2{};
    PW21Z_OP::TrafficLane tl{11};
    PW21Z_OP::TrafficLane tl2{11};
    PW21Z_OP::TrafficLaneTeleporter teleport{tl, tl2};

    tl.add_TrafficParticipant(std::move(tp));
    tl.get_TrafficParticipant(tp._uid);
    tl.get_TrafficLaneTeleporter(teleport._uid).teleport_TrafficParticipant(tp._uid);
    tl2.get_TrafficParticipant(tp._uid);

    return 0;
}