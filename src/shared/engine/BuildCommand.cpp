#include "BuildCommand.hpp"

namespace engine {
    BuildCommand::BuildCommand(int trainer, std::array<std::pair<int, model::Item*>, 3> pairings) {
        this->trainer = trainer;
        this->creatureItemPairings = pairings;
    }

    BuildCommand::~BuildCommand() {}

    bool BuildCommand::Execute(state::Battle* battle) {
        return (this->trainer ? battle->GetTrainerB() : battle->GetTrainerA())->GetParty()->SetParticipatingTeam(creatureItemPairings);
    }
    void BuildCommand::Revert(state::Battle *battle) {
        (this->trainer ? battle->GetTrainerB() : battle->GetTrainerA())->GetParty()->FreeParticipatingTeam();
    }
}
