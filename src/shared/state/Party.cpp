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

    Party::~Party()
    {

    }

    void Party::LoadFromModel(model::Model* modelData, std::array<std::string, 6> creatureNameList)
    {
        for(size_t i = 0; i < creatures.size(); i++)
        {
            creatures[i] = modelData->GetCreature(creatureNameList[i]);
        }
    }

    void Party::SetParticipatingTeam(std::array<int,3> creaturesIndexes)
    {
        Reset();

        participatingCreatures[0] = new Creature(creatures[creaturesIndexes[0]]);
        SwitchCreatureState(0, CreatureState::active );
        participatingCreatures[1] = new Creature(creatures[creaturesIndexes[1]]);
        SwitchCreatureState(1, CreatureState::sub );
        participatingCreatures[2] = new Creature(creatures[creaturesIndexes[2]]);
        SwitchCreatureState(2, CreatureState::sub );
        
        activeCreature = participatingCreatures[0];
    }

    void Party::SwitchCreatureState(int creatureIndex, CreatureState newCreatureState)
    {
        participatingCreatures[creatureIndex]->UpdateState(newCreatureState);
    }

    void Party::GiveItem(model::Model* modelData, std::string itemName, int creatureIndex)
    {
        if(remainingItems > 0)
        {
            Item* item = new Item(modelData->GetItem(itemName));
            participatingCreatures[creatureIndex]->GiveItem(item);
            remainingItems--;
        }
        else
        {
            throw std::invalid_argument("Action not allowed (No more Items available)");
        }        
    }

    std::string Party::GetName(int creatureIndex)
    {
        return participatingCreatures[creatureIndex]->GetName();
    }

    int Party::GetBaseHP(int creatureIndex)
    {
        return participatingCreatures[creatureIndex]->GetStatBase(StatName::hp);
    }

    int Party::GetCurrentHP(int creatureIndex)
    {
        return participatingCreatures[creatureIndex]->GetStatCurrent(StatName::hp);
    }

    Item* Party::GetItem(int creatureIndex)
    {
        if(participatingCreatures[creatureIndex]->GetItem() != nullptr)
        {
            return participatingCreatures[creatureIndex]->GetItem();
        }
        else
        {
            std::cout << "No item equipped" << std::endl;
            return nullptr;
        }
    }

    Creature* Party::GetActiveCreature()
    {
        return activeCreature;
    }

    void Party::Reset()
    {
        for(int i = 0; i < (int)participatingCreatures.size(); i++)
        {
            if(participatingCreatures[i] != nullptr)
            {
                participatingCreatures[i] = nullptr;
            }
        }

        remainingItems = 2;
        bannedCreature = -1;
        activeCreature = nullptr;
    }

    void Party::SetBannedCreature(int creatureIndex)
    {
        if(creatureIndex >= 0 && creatureIndex < 6)
        {
            bannedCreature = creatureIndex;
        }
        else
        {
            throw std::invalid_argument("Index out of bounds (Must be between 0 and 5)");
        }
            
    }

    void Party::SetActiveCreature(int creatureIndex)
    {
        if(creatureIndex >= 0 && creatureIndex < (int)participatingCreatures.size())
        {
            if(participatingCreatures[creatureIndex]->GetState() == CreatureState::sub)
            {
                activeCreature->UpdateState(CreatureState::sub);
                participatingCreatures[creatureIndex]->UpdateState(CreatureState::active);
                activeCreature = participatingCreatures[creatureIndex];
            }
            else
            {
                throw std::invalid_argument("Invalid state (Is either Active or KO)");
            }
        }
        else
        {
            throw std::invalid_argument("Index out of bounds (Must be between 0 and 2)");
        }
    }
}
