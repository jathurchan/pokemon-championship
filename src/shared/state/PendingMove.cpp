#include "PendingMove.hpp"
#include <random>

namespace state
{
    PendingMove::PendingMove()
    {
        
    }

    state::PendingMove::~PendingMove()
    {

    }

    bool operator<(const PendingMove &lhs, const PendingMove &rhs)
    {
        if (lhs.procSpeed == rhs.procSpeed)
            return std::rand() % 2;
        return lhs.procSpeed < rhs.procSpeed;
    }
}
