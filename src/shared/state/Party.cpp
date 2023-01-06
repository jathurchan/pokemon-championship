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
        std::cout << creatures.size() << std::endl;
    }

    void Party::SetParticipatingTeam(std::array<int,3> creaturesIndexes)
    {
        participatingCreatures[0] = new Creature(creatures[creaturesIndexes[0]]);
        SwitchCreatureState(0, CreatureState::active );
        participatingCreatures[1] = new Creature(creatures[creaturesIndexes[1]]);
        SwitchCreatureState(1, CreatureState::sub );
        participatingCreatures[2] = new Creature(creatures[creaturesIndexes[2]]);
        SwitchCreatureState(2, CreatureState::sub );
        
        UpdateActiveCreature();
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
            std::cout << "No more items available !" << std::endl;
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

    Creature& Party::GetActiveCreature()
    {
        return activeCreature;
    }

    void Party::UpdateActiveCreature()
    {
        for(auto c : participatingCreatures)
        {
            if(c->GetState() == CreatureState::active) 
            {
                activeCreature = *c;
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
