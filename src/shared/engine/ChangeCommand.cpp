#include "ChangeCommand.hpp"

namespace engine {
    ChangeCommand::ChangeCommand(int trainer, int replaceId) {
        this->trainer = trainer;
        this->replaceId = replaceId;
    }

    ChangeCommand::~ChangeCommand() {}

    bool ChangeCommand::Execute(state::Battle *battle) {
        state::Party* party = (trainer ? battle->GetTrainerB() : battle->GetTrainerA())->GetParty();
        this->prevPartyState = *party;
        *this->prevCreatureState = *party->GetActiveCreature();
        return party->SetCreatureActive(replaceId);
    }

    void ChangeCommand::Revert(state::Battle *battle) {
        state::Party* party = (trainer ? battle->GetTrainerB() : battle->GetTrainerA())->GetParty();
        *party = this->prevPartyState;
        *party->GetActiveCreature() = *this->prevCreatureState;
    }
}
