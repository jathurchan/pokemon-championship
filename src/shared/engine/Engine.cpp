#include "Engine.hpp"

namespace engine 
{
    engine::Engine::Engine() 
    {

    }

    void Engine::Execute(Command commandA, Command commandB, state::Battle *battle)
    {
        commandA.Execute(battle);
        commandB.Execute(battle);

        ResolveTurn(battle);
    }

    void Engine::ResolveTurn(state::Battle* battle) {
        state::PendingMove pMove;
        while ((pMove = battle->PopQueue()).procSpeed) {
            state::Creature* target = (pMove.source ? battle->GetTrainerB() : battle->GetTrainerA())->GetActiveCreature();
            target->ReceiveDamage(pMove.rawDamage, pMove.type);
            target = (!pMove.source != pMove.aura->TargetsSelf() ? battle->GetTrainerA() : battle->GetTrainerB())->GetActiveCreature();
            target->ApplyAura(pMove.aura);
        }
    }
}
