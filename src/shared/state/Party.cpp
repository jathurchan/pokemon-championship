#include "Party.hpp"
#include <iostream>

namespace model
{
    class Model;
}

namespace state {

    Party::Party() = default;

    Party::~Party() = default;

    void Party::LoadFromModel(model::Model modelData, std::array<std::string, 6> creatureNameList)
    {
        for(int i = 0; i < (int)creatures.size(); i++)
        {
            creatures[i] = modelData.GetCreature(creatureNameList[i]);
        }
    }

    void Party::SetParticipatingTeam(std::array<int,3> creaturesIndexes)
    {
        for(int i = 0; i < (int)creaturesIndexes.size(); i++)
        {
            participatingCreatures[i] = Creature(*creatures[creaturesIndexes[i]]);
            SwitchCreatureState(i, (i == 0) ? CreatureState::active : CreatureState::sub);
        }
    }

    void Party::SwitchCreatureState(int creatureIndex, CreatureState newCreatureState)
    {
        participatingCreatures[creatureIndex].UpdateState(newCreatureState);
    }

    void Party::GiveItem(model::Model modelData, std::string itemName, int creatureIndex)
    {
        if(remainingItems > 0)
        {
            Item item = Item(*modelData.GetItem(itemName));
            participatingCreatures[creatureIndex].GiveItem(item);
            remainingItems--;
        }
        else
        {
            std::cout << "No more items available !" << std::endl;
        }        
    }

    std::string Party::GetName(int creatureIndex)
    {
        return participatingCreatures[creatureIndex].GetName();
    }

    int Party::GetBaseHP(int creatureIndex)
    {
        return participatingCreatures[creatureIndex].GetStatBase(StatName::hp);
    }

    int Party::GetCurrentHP(int creatureIndex)
    {
        return participatingCreatures[creatureIndex].GetStatCurrent(StatName::hp);
    }

    Item Party::GetItem(int creatureIndex)
    {
        if(&participatingCreatures[creatureIndex].GetItem() != nullptr)
        {
            return participatingCreatures[creatureIndex].GetItem();
        }
        else
        {
            std::cout << "No item equipped" << std::endl;
            return;
        }
    }

    Creature& Party::GetActiveCreature()
    {
        return activeCreature;
    }

    void Party::UpdateActiveCreature()
    {
        for(auto c : participatingCreatures)
        {
            if(c.GetState() == CreatureState::active) 
            {
                activeCreature = c;
                break;
            }
        }
        if(!(&activeCreature))
        {
            std::cout << "Unitialized Active Creature" << std::endl;
        }
    }


    void Party::Reset()
    {
        remainingItems = 2;
    }
}
