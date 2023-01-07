#include "PendingMove.hpp"

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
        return lhs.procSpeed < rhs.procSpeed;
    }
}
