#include "BuildCommand.hpp"
#include <iostream>

namespace engine {
    BuildCommand::BuildCommand(int trainer, std::array<std::pair<int, model::Item*>, 3> pairings) {
        this->trainer = trainer;
        this->creatureItemPairings = pairings;
    }

    BuildCommand::~BuildCommand() {}

    bool BuildCommand::Execute(state::Battle* battle) {
        state::Trainer* trainer = this->trainer ? battle->GetTrainerB() : battle->GetTrainerA();
        if (trainer->GetParty()->SetParticipatingTeam(creatureItemPairings)) {
            std::cout << trainer->GetName() << "'s team is ready!\n";
            return true;
        }
        return false;
    }
    void BuildCommand::Revert(state::Battle *battle) {
        (this->trainer ? battle->GetTrainerB() : battle->GetTrainerA())->GetParty()->FreeParticipatingTeam();
    }
}
