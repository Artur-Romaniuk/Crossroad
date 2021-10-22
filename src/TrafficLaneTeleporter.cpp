#include "TrafficLane.h"
#include "TrafficLaneTeleporter.h"

namespace PW21Z_OP
{
    void TrafficLaneTeleporter::teleport_TrafficParticipant(long long tp_uid)
    {
        _destination.add_TrafficParticipant(_origin.get_TrafficParticipant(tp_uid));
    }
}