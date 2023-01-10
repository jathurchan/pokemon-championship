#include "MoveCommand.hpp"
#include <iostream>

namespace engine {
    MoveCommand::MoveCommand(int trainer, int moveId) {
        this->trainer = trainer;
        this->moveId = moveId;
    }

    MoveCommand::~MoveCommand() {}

    bool MoveCommand::Execute(state::Battle *battle) {
        state::Creature* creature = (trainer ? battle->GetTrainerB() : battle->GetTrainerA())->GetParty()->GetActiveCreature();
        state::Move* move = creature->GetMove(moveId);
        if (move->GetCurrPP() <= 0) {
            std::cout << creature->GetName() << " can't use " << move->GetName() << " anymore!\n";
            return false;
        }
        if (creature->GetState() == state::ko) {
            std::cout << creature->GetName() << " needs rest.\n";
            return false;
        }
        
        move->DecrementPP();

        state::PendingMove pMove = state::PendingMove();
        pMove.source = this->trainer;
        pMove.procSpeed = creature->GetStatCurrent(state::spd) + (move->HasPriority() ? 1000 : 0);
        pMove.rawDamage = creature->GetStatCurrent(state::atk) * move->GetPower() / 200;
        pMove.type = move->GetType();
        pMove.aura = move->GetAura();
        battle->PushQueue(pMove);
        std::cout << creature->GetName() << " will use " << move->GetName() << " for "
        << pMove.rawDamage << " raw damage this turn, with speed " << pMove.procSpeed << ".\n";
        return true;
    }

    void MoveCommand::Revert(state::Battle* battle) {
        state::Move* move = (trainer ? battle->GetTrainerB() : battle->GetTrainerA())->GetParty()->GetActiveCreature()->GetMove(moveId);
        move->IncrementPP();
        battle->PopQueue();
    }
}
