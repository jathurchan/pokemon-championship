#include "BuildCommand.hpp"

namespace engine {
    engine::BuildCommand::BuildCommand(int trainer, std::array<std::pair<int, std::string>, 3> pairings) {
        this->trainer = trainer;
        this->creatureItemPairings = pairings;
    }

    void engine::BuildCommand::Execute(state::Battle* battle) {
        state::Party* party = (this->trainer ? battle->GetTrainerB() : battle->GetTrainerA())->GetParty();
        std::array<int, 3> creatures;
        for (int i = 0; i < 3; i++) {
            creatures[i] = creatureItemPairings[i].first;
        }
        party->SetParticipatingTeam(creatures);

        for (int i = 0; i < 3; i++) {
            party->GiveItem(new model::Model, creatureItemPairings[i].second, i);   // !!! NEED TO FIX MODEL DEPENDENCY; CURRENTLY USING EMPTY MODEL !!!
        }
    }
}
