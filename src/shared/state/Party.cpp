#include "Party.hpp"
#include <iostream>

namespace model
{
    class Model;
}

namespace state {

    Party::Party()
    {
        Reset();
    }

    Party::~Party() = default;

    void Party::LoadFromModel(model::Model* modelData, std::array<std::string, 6> creatureNameList)
    {
        for(int i = 0; i < (int)creatures.size(); i++)
        {
            creatures[i] = modelData->GetCreature(creatureNameList[i]);
        } 
    }

    void Party::SetParticipatingTeam(std::array<int,3> creaturesIndexes)
    {
        participatingCreatures[0] = Creature(*creatures[creaturesIndexes[0]]);
        SwitchCreatureState(0, CreatureState::active );
        participatingCreatures[1] = Creature(*creatures[creaturesIndexes[1]]);
        SwitchCreatureState(1, CreatureState::sub );
        participatingCreatures[2] = Creature(*creatures[creaturesIndexes[2]]);
        SwitchCreatureState(2, CreatureState::sub );
    }

    void Party::SwitchCreatureState(int creatureIndex, CreatureState newCreatureState)
    {
        participatingCreatures[creatureIndex].UpdateState(newCreatureState);
    }

    void Party::GiveItem(model::Model* modelData, std::string itemName, int creatureIndex)
    {
        if(remainingItems > 0)
        {
            Item* item = new Item(modelData->GetItem(itemName));
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

    Item* Party::GetItem(int creatureIndex)
    {
        if(participatingCreatures[creatureIndex].GetItem() != nullptr)
        {
            return participatingCreatures[creatureIndex].GetItem();
        }
        else
        {
            std::cout << "No item equipped" << std::endl;
            return nullptr;
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
