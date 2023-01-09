#include "MoveCommand.hpp"
#include <iostream>

namespace engine {
    engine::MoveCommand::MoveCommand(int trainer, int moveId) {
        this->trainer = trainer;
        this->moveId = moveId;
    }

    MoveCommand::~MoveCommand() {}

    void engine::MoveCommand::Execute(state::Battle *battle) {
        state::Creature* creature = (trainer ? battle->GetTrainerB() : battle->GetTrainerA())->GetParty()->GetActiveCreature();
        state::Move* move = creature->GetMove(moveId);
        if (move->GetCurrPP() <= 0)
            return;
        
        move->DecrementPP();

        state::PendingMove pMove = state::PendingMove();
        pMove.source = this->trainer;
        pMove.procSpeed = creature->GetStatCurrent(state::spd) + move->HasPriority() ? 1000 : 0;
        pMove.rawDamage = creature->GetStatCurrent(state::atk) * move->GetPower() / 200;
        pMove.type = move->GetType();
        pMove.aura = move->GetAura();
        battle->PushQueue(pMove);
        char* log = (char*)malloc(64 * sizeof(char));
        sprintf(log, "%s will use %s for %d raw damage this turn, with speed %d.\n", creature->GetName().c_str(), move->GetName().c_str(), pMove.rawDamage, pMove.procSpeed);
        std::cout << log;
    }
}
