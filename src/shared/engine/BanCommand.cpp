#include "BanCommand.hpp"
#include <iostream>

namespace engine {
    BanCommand::BanCommand(int trainer, int creatureId) {
        this->trainer = trainer;
        this->creatureId = creatureId;
    }

    BanCommand::~BanCommand() {}

    bool BanCommand::Execute(state::Battle* battle) {
        state::Trainer* sourceTrainer;
        state::Trainer* targetTrainer;
        if (trainer) {
            sourceTrainer = battle->GetTrainerB();
            targetTrainer = battle->GetTrainerA();
        } else {
            sourceTrainer = battle->GetTrainerA();
            targetTrainer = battle->GetTrainerB();
        }
        std::cout << sourceTrainer->GetName() << " bans " << targetTrainer->GetName() << "'s creature n°" << creatureId << ".\n";
        return targetTrainer->GetParty()->SetBannedCreature(creatureId);
    }

    void BanCommand::Revert(state::Battle* battle) {
        (this->trainer ? battle->GetTrainerA() : battle->GetTrainerB())->GetParty()->Reset();
    }
}
