#include <iostream>
#include <utility>
#include "TrafficLane.h"
#include "TrafficParticipant.h"

int main()
{
    PW21Z_OP::TrafficParticipant tp{"Hi"};
    PW21Z_OP::TrafficParticipant tp2{"Hello"};
    PW21Z_OP::TrafficLane tl{11};
    PW21Z_OP::TrafficLane tl2{11};
    PW21Z_OP::TrafficLaneTeleporter teleport{tl, tl2};

    tl.add_TrafficParticipant(std::move(tp));
    tl.add_TrafficLaneTeleporter(std::move(teleport));
    tl.get_TrafficLaneTeleporter(teleport._uid).teleport_TrafficParticipant(tp._uid);
    for (auto &i : tl.traffic_participants_container)
    {
        std::cout << 0;
    }
    for (auto &i : tl2.traffic_participants_container)
    {
        std::cout << 1;
    }

    return 0;
}