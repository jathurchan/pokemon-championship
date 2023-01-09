#include "BanCommand.hpp"

namespace engine {
    BanCommand::BanCommand(int trainer, int creatureId) {
        this->trainer = trainer;
        this->creatureId = creatureId;
    }

    BanCommand::~BanCommand() {}

    bool BanCommand::Execute(state::Battle* battle) {
        return (this->trainer ? battle->GetTrainerA() : battle->GetTrainerB())->GetParty()->SetBannedCreature(creatureId);
    }

    void BanCommand::Revert(state::Battle* battle) {
        (this->trainer ? battle->GetTrainerA() : battle->GetTrainerB())->GetParty()->Reset();
    }
}
