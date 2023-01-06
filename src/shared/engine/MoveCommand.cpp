#include "MoveCommand.hpp"

namespace engine {
    engine::MoveCommand::MoveCommand(int trainer, int moveId) {
        this->trainer = trainer;
        this->moveId = moveId;
    }

    void engine::MoveCommand::Execute(state::Battle *battle) {
        state::Creature creature = (trainer ? battle->GetTrainerB() : battle->GetTrainerA())->GetParty()->GetActiveCreature();
        state::Move* move = creature.GetMove(moveId);
        if (move->GetCurrPP() == 0)
            return;
        
        move->DecrementPP();

        int source = this->trainer;
        int procSpeed = creature.GetStatCurrent(state::spd) + move->HasPriority() ? 1000 : 0;
        int rawDamage = creature.GetStatCurrent(state::atk) * move->GetPower() / 200;
        model::Type* type = move->GetType();
        bool auraTargetsSelf = move->GetAura();
        //TODO : get all this data back up to the engine for further process
    }
}