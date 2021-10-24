#pragma once
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

namespace PW21Z_OP
{
    class ID
    {
    public:
        long long _uid;
        boost::uuids::uuid _uuid;
        ID() : _uid{get_uid()}, _uuid{boost::uuids::random_generator()()} {}
        ID(const ID &other) : _uid{other._uid}, _uuid{other._uuid} {}
        ID &operator=(const ID &other)
        {
            _uid = other._uid;
            _uuid = other._uuid;
            return *this;
        }

        bool operator==(const ID &other) const
        {
            return (_uuid == other._uuid) && (_uid == other._uid);
        }

    private:
        int get_uid()
        {
            static long long uid_gen = 0;
            return uid_gen++;
        }
    };
}