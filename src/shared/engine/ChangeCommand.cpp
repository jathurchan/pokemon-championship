#include "ChangeCommand.hpp"
#include <iostream>

namespace engine {
    ChangeCommand::ChangeCommand(int trainer, int replaceId) {
        this->trainer = trainer;
        this->replaceId = replaceId;
    }

    ChangeCommand::~ChangeCommand() {}

    bool ChangeCommand::Execute(state::Battle *battle) {
        state::Party* party = (trainer ? battle->GetTrainerB() : battle->GetTrainerA())->GetParty();
        activeIndexBackup = party->SaveStats(statsBackup);
        std::string name = party->GetActiveCreature()->GetName();
        if (party->SetCreatureActive(replaceId)) {
            std::cout << name << " retreats to let " << party->GetActiveCreature()->GetName() << " in!\n";
            return true;
        }
        return false;
    }

    void ChangeCommand::Revert(state::Battle *battle) {
        state::Party* party = (trainer ? battle->GetTrainerB() : battle->GetTrainerA())->GetParty();
        party->SetCreatureActive(activeIndexBackup);
        party->RestoreStats(statsBackup);
    }
}
