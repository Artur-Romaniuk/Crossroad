#pragma once
#include <iostream>
#include <string>
#include "ID.h"

namespace PW21Z_OP
{
    class TrafficParticipant : public ID
    {
    public:
        std::string _name;
        explicit TrafficParticipant(const std::string &name) : _name{name} {}
        TrafficParticipant(const TrafficParticipant &tl)
        {
            std::cout << "Copy";
        }
        TrafficParticipant &operator=(const TrafficParticipant &tl)
        {
            std::cout << "Copy";
            return *this;
        }
        TrafficParticipant(TrafficParticipant &&tl)
        {
            std::cout << "Move";
        }
        TrafficParticipant &operator=(TrafficParticipant &&tl)
        {
            std::cout << "Move";
            return *this;
        }
    };
}
