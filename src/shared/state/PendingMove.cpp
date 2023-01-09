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
        return (lhs.procSpeed < rhs.procSpeed) ? true : (lhs.procSpeed == rhs.procSpeed ? std::rand() % 2 : false);
    }
}
