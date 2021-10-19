#pragma once

namespace PW21Z_OP
{
    class ID
    {
    public:
        const long long _uid;
        ID() : _uid{get_uid()} {}

    private:
        int get_uid()
        {
            static long long uid_gen = 0;
            return uid_gen++;
        }
    };
}