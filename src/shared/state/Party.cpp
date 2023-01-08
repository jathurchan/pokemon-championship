#include "Party.hpp"
#include <iostream>
#include "unordered_map"

namespace model
{
    class Model;
}

namespace state {

    Party::Party()
    {
        participatingCreatures.fill(nullptr);
        creatures.fill(nullptr);
        Reset();
    }

    Party::~Party()
    {
        FreeParticipatingTeam();
    }

    void Party::LoadFromModel(model::Model* modelData, std::array<std::string, 6> creatureNameList)
    {
        for(size_t i = 0; i < creatures.size(); i++)
        {
            creatures[i] = modelData->GetCreature(creatureNameList[i]);
        }
    }

    bool Party::SetParticipatingTeam(std::array<int,3> creaturesIndexes)
    {
        FreeParticipatingTeam();
        for(int i = 0; i < (int)creaturesIndexes.size(); i++)
        {
            if(bannedCreature == creaturesIndexes[i])
            {
                std::cout << "Index : " << creaturesIndexes[i] << " is equal to the banned creature" << std::endl; 
                return false;
            }
        }
        participatingCreatures[0] = new Creature(creatures[creaturesIndexes[0]]);
        SetCreatureActive(0);
        participatingCreatures[1] = new Creature(creatures[creaturesIndexes[1]]);
        participatingCreatures[2] = new Creature(creatures[creaturesIndexes[2]]);
        return true;
    }

    void Party::GiveItem(model::Item* modelItem, int creatureIndex)
    {
        if(remainingItems > 0)
        {
            participatingCreatures[creatureIndex]->GiveItem(modelItem);
            remainingItems--;
        }
        else
        {
            std::cout << "Action not allowed (No more Items available)" << std::endl;
        }        
    }

    std::string Party::GetName(int creatureIndex)
    {
        return participatingCreatures[creatureIndex]->GetName();
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
        bannedCreature = -1;
        remainingItems = 2;
        activeCreature = nullptr;
    }

    void Party::FreeParticipatingTeam()
    {
        for(int i = 0; i < (int)participatingCreatures.size(); i++)
        {
            if(participatingCreatures[i] != nullptr)
            {
                delete participatingCreatures[i];
                participatingCreatures[i] = nullptr;
            }
        }
    }

    bool Party::SetBannedCreature(int creatureIndex)
    {
        if(creatureIndex >= 0 && creatureIndex < 6)
        {
            bannedCreature = creatureIndex;
        }
        else
        {
            std::cout << "Index out of bounds (Must be between 0 and 5)" << std::endl;
        }
        return (bannedCreature != -1);            
    }

    bool Party::SetCreatureActive(int creatureIndex)
    {
        if(creatureIndex >= 0 && creatureIndex < (int)participatingCreatures.size())
        {
            if(participatingCreatures[creatureIndex]->GetState() == CreatureState::sub)
            {
                if(activeCreature != nullptr)
                {
                    activeCreature->UpdateState(CreatureState::sub);
                }
                participatingCreatures[creatureIndex]->UpdateState(CreatureState::active);
                activeCreature = participatingCreatures[creatureIndex];
            }
            else
            {
                std::cout << "Invalid state (Is either Active or KO)" << std::endl;                
            }
        }
        else
        {
            std::cout << "Index out of bounds (Must be between 0 and 2)" << std::endl;
            return false;
        }

        return participatingCreatures[creatureIndex]->GetState() == CreatureState::active;
    }

    int Party::GetRemainingItems()
    {
        return remainingItems;
    }
   
}
