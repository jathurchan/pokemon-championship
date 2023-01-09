#include "ChangeCommand.hpp"

namespace engine {
    engine::ChangeCommand::ChangeCommand(int trainer, int replaceId) {
        this->trainer = trainer;
        this->replaceId = replaceId;
    }

    ChangeCommand::~ChangeCommand() {}

    void engine::ChangeCommand::Execute(state::Battle *battle) {
        state::Party* party = (trainer ? battle->GetTrainerB() : battle->GetTrainerA())->GetParty();
        party->SetCreatureActive(replaceId);
    }
}
