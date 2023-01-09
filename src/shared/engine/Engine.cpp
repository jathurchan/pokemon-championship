#include "Engine.hpp"

namespace engine 
{
    Engine::Engine() 
    {

    }

    bool Engine::Execute(Command* commandA, Command* commandB, state::Battle *battle)
    {
        int failBitmap = 0;
        failBitmap |= !commandA->Execute(battle) << 0;
        failBitmap |= !commandB->Execute(battle) << 1;

        if (failBitmap) {
            if ((failBitmap & 0x01) && !(failBitmap & 0x02))
                commandB->Revert(battle);
            if ((failBitmap & 0x02) && !(failBitmap & 0x01))
                commandA->Revert(battle);
            return false;
        }

        ResolveTurn(battle);
        return true;
    }

    void Engine::ResolveTurn(state::Battle* battle) {
        state::PendingMove pMove;
        while ((pMove = battle->PopQueue()).procSpeed) {
            state::Creature* target = (pMove.source ? battle->GetTrainerB() : battle->GetTrainerA())->GetActiveCreature();
            target->ReceiveDamage(pMove.rawDamage, pMove.type);
            target = (!pMove.source != pMove.aura->TargetsSelf() ? battle->GetTrainerB() : battle->GetTrainerA())->GetActiveCreature();
            target->ApplyAura(pMove.aura);
        }
    }
}
