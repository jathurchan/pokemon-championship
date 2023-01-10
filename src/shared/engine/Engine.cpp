#include "Engine.hpp"
#include <iostream>
#include <ctime>

namespace engine 
{
    Engine::Engine() 
    {
        std::srand(std::time(nullptr));
    }

    bool Engine::Execute(Command* commandA, Command* commandB, state::Battle *battle)
    {
        int failBitmap = 0;
        failBitmap |= !commandA->Execute(battle) << 0;
        failBitmap |= !commandB->Execute(battle) << 1;

        if (failBitmap) {
            std::cout << "---- REVERT TURN -----\n";
            if ((failBitmap & 0x01) && !(failBitmap & 0x02))
                commandB->Revert(battle);
            if ((failBitmap & 0x02) && !(failBitmap & 0x01))
                commandA->Revert(battle);
            return false;
        }

        ResolveTurn(battle);
        std::cout << "------ END TURN ------\n";
        return true;
    }

    void Engine::ResolveTurn(state::Battle* battle) {
        state::PendingMove pMove;
        while ((pMove = battle->PopQueue()).procSpeed) {
            if ((pMove.source ? battle->GetTrainerB() : battle->GetTrainerA())->GetParty()->GetActiveCreature()->GetState() == state::ko)
                continue;
            state::Creature* target = (pMove.source ? battle->GetTrainerA() : battle->GetTrainerB())->GetActiveCreature();
            target->ReceiveDamage(pMove.rawDamage, pMove.type);
            target = (!pMove.source != pMove.aura->TargetsSelf() ? battle->GetTrainerB() : battle->GetTrainerA())->GetActiveCreature();
            target->ApplyAura(pMove.aura);
        }
    }
}
