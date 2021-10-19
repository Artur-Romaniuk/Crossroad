#include <iostream>
#include "TrafficLane.h"
#include "TrafficParticipant.h"

int main()
{
    PW21Z_OP::TrafficParticipant tp{};
    PW21Z_OP::TrafficParticipant tp2{};
    PW21Z_OP::TrafficLane tl{11};
    PW21Z_OP::TrafficLaneWithLocalization tlwl{10, 1, 2, 3};
    PW21Z_OP::Localization loc{3, 5, 7};
    PW21Z_OP::TrafficLaneWithLocalization tlwl2{20, loc};

    std::cout << tlwl2._localization._x << tlwl2._localization._y << tlwl2._localization._z;

    return 0;
}