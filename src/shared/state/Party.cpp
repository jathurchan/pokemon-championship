#include "Party.hpp"
#include <iostream>

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

    bool Party::SetParticipatingTeam(std::array<std::pair<int, model::Item*>,3> pairs)
    {
        FreeParticipatingTeam();
        for(int i = 0; i < (int)pairs.size(); i++)
        {
            if(bannedCreature == pairs[i].first)
            {
                std::cout << creatures[pairs[i].first]->GetName() << " is banned.\n"; 
                return false;
            }
            participatingCreatures[i] = new Creature(creatures[pairs[i].first]);
            if(!GiveItem(pairs[i].second, i))
            {
                FreeParticipatingTeam();
                return false;
            }
        }
        SetCreatureActive(0);
        
        return true;
    }

    bool Party::GiveItem(model::Item* modelItem, int creatureIndex)
    {
        if(modelItem == nullptr)
        {
            return true;
        }
        
        if(remainingItems > 0)
        {
            participatingCreatures[creatureIndex]->GiveItem(modelItem);
            remainingItems--;
            return true;
        }

        std::cout << "Action not allowed (No more Items available)" << std::endl;
        return false;      
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
        activeCreature = nullptr;
        remainingItems = 2;
    }

    bool Party::SetBannedCreature(int creatureIndex)
    {
        if(creatureIndex >= 0 && creatureIndex < 6)
        {
            bannedCreature = creatureIndex;
        }
        else
        {
            std::cout << "Index " << creatureIndex << " out of bounds (Must be between 0 and 5)" << std::endl;
        }
        return (bannedCreature != -1);            
    }

    bool Party::SetCreatureActive(int creatureIndex)
    {
        if(creatureIndex < 0 || creatureIndex >= (int)participatingCreatures.size())
        {
            std::cout << "Index " << creatureIndex << " out of bounds (Must be between 0 and 2)\n";
            return false;
        }
        switch (participatingCreatures[creatureIndex]->GetState())
        {
            case CreatureState::ko:
                std::cout << participatingCreatures[creatureIndex]->GetName() << " needs some more rest...\n";
                return false;

            case CreatureState::active:
                std::cout << participatingCreatures[creatureIndex]->GetName() << " is already on the battlefield!\n";
                return false;

            case CreatureState::sub:
                if(activeCreature != nullptr) activeCreature->UpdateState(CreatureState::sub);
                participatingCreatures[creatureIndex]->UpdateState(CreatureState::active);
                activeCreature = participatingCreatures[creatureIndex];
                return true;
                
            default:
                std::cout << "Unknown creature state.\n";
                return false;
        }
    }


    int Party::SaveStats(std::array<int,4>& backup)
    {
        backup[hp] = this->activeCreature->GetStatCurrent(hp);
        backup[atk] = this->activeCreature->GetStatCurrent(atk);
        backup[def] = this->activeCreature->GetStatCurrent(def);
        backup[spd] = this->activeCreature->GetStatCurrent(spd);
        for (size_t i = 0; i < participatingCreatures.size(); i++)
        {
            if (participatingCreatures[i] == activeCreature) return i;
        }
        return -1;
    }

    void Party::RestoreStats(const std::array<int,4>& backup)
    {
        this->activeCreature->SetStatCurrent(backup[hp], hp);
        this->activeCreature->SetStatCurrent(backup[atk], atk);
        this->activeCreature->SetStatCurrent(backup[def], def);
        this->activeCreature->SetStatCurrent(backup[spd], spd);
    }

}
