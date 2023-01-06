#include "Stat.hpp"

namespace state {
    
    Stat::Stat()
    {

    }

    Stat::Stat(StatName statName, int baseValue)
    {
        this->statName = statName;
        this->baseValue = baseValue;
        currentValue = baseValue;
    }

    Stat::~Stat()
    {
        
    }
    
    int Stat::GetBase()
    {
        return baseValue;
    }

    int Stat::GetCurrent()
    {
        return currentValue;
    }

    void Stat::Update(int newValue)
    {
        currentValue = (newValue < 0) ? 0 : newValue;
    }

    StatName Stat::GetStatName()
    {
        return statName;
    }
}
