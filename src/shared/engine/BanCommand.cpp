#include "BanCommand.hpp"

namespace engine {
    engine::BanCommand::BanCommand(int trainer, int creatureId) {
        this->trainer = trainer;
        this->creatureId = creatureId;
    }

    void engine::BanCommand::Execute(state::Battle* battle) {
        state::Trainer* trainer = this->trainer ? battle->GetTrainerA() : battle->GetTrainerB();  //Get opponent trainer
        trainer->GetParty()->SetBannedCreature(creatureId);
    }
}
