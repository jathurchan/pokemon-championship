# Pokémon Championship

## Archetype

> Turn-based Duels (Pokémon-like) following a championship system (+ tournament as tie-breaker)

## Game Rules

### Championship rules

> The championship is composed of 8 players who will face each other twice (two-legged matches) for a total of 14 encounters each. 
> The championship will include 5 phases :
> - `Team Creation`
> - `First Leg Encounters`
> - `Mid-Season Pause`
> - `Second Leg Encounters`
> - `Tie-breaker + Final Ladder`

#### Leaderboard

> At the end of each encounter, there is always a winner and a loser (no ties are possible). 
> Players will be progressively ranked (after each round) based on the number of wins/loses and the number of creatures knocked-out/saved.

#### Winning condition

> The winner is the player that detains the first place in the ladder.

#### Conditions of ranking 

> Players are ranked based on the points scored at each round. 
> If there is a tie with other players, those are ranked based on their knocked-out/saved ratio.

#### Tournament mode

> At the end of the last round of the Second Leg Encounters, if there are players with the exact same amount of points and knocked-out/saved ratio, a tie-break will take place between them to define their final rank.<br/>
> A random tournament tree is generated with Best of One format between the tied players.

#### Team Creation

> Each player has to choose a team of 6 creatures from the catalog. Note that players would not be able to modify their choices during the championship, except during the mid-season pause.

#### Mid-Season Pause

> Each player has the possibility to replace* one of their creatures with another one picked from the catalog. Note that players would not be able to modify their choices until the end of the championship.
> <br/><br/>* *A player can decide to do not replace any of his creatures during this phase and keep the same team for the second leg.*

#### First Leg Encounters

> Each player will encounter other participants once in best of one format matches (for a total of 7 encounters).

#### Second Leg Encounters

> Each player will encounter other participants once in best of one format matches (for a total of 7 encounters).

#### Tie-breakers + Final Ladder

> During this phase take place tie-breakers before displaying the final ladder. At this moment players will know their final rank.


### Combat rules

#### Before the beginning of the combat

> Each player will have access to their opponent's creature list and will decide to ban one of them. The banned creature will not be able to participate in this encounter.<br/><br/>
> With the remaining creatures (5), each player will build their team of 3 creatures in blind mode (players do not see in real time their opponent's choices).<br/><br/>
> Within their team of 3, players will be able to (this is not mandatory) set 2 items (see Item section).
> At last, players choose the first creature to send to the battlefield.

#### During the combat

> Each player will have access to their opponent's creature list and will decide to ban one of them. The banned creature will not be able to participate in this encounter.<br/><br/>
> With the remaining creatures (5), each player will build their team of 3 creatures in blind mode (players do not see in real time their opponent's choices).<br/><br/>
> Within their team of 3, players will be able to (this is not mandatory) set 2 items (see Item section).
> At last, players choose the first creature to send to the battlefield.


Combat

Il place 2 items sur 2 créatures distinctes (1 sur chaque) parmi:
Activation dès le début
Boost attaque
Boost vitesse
Boost défense
Activation sous conditions
Soin (HP en dessous de 50 %)
Chaque joueur choisit leur première créature


Pendant (tour par tour)
Chaque joueur choisit une action (l’une ou l’autre):

Attaquer (4 choix)

Remplacer la créature (parmi les créatures vivantes, au max 2) (action prioritaire)

Chaque joueur valide la fin de tour

A la mort d’une des créatures en jeu
Le propriétaire de la créature morte choisit son remplaçant et valide le choix et on revient à l’état précédent.
L’autre joueur attend la validation.


A la mort de la dernière créature d'un joueur
L’adversaire est déclaré vainqueur (Il gagne un point…)
Le perdant ne gagne rien.
Le duel se termine.



Élément de jeu

Créatures

Stats
HP (Points de vie)
Atk (Attaque)
Def (Défense)
Spd (Vitesse)

Type (faiblesses + avantages)
Set de 4 Attaques


Type
Chaque type a 2 avantages et 2 faiblesses
10 types
Dawn
Twilight
Celestial
Infernal
Tempest
Atlas
Distorsion
Abyss
Deepwood
Spirit

Exemple générique à trois types



Type A
Type B
Type C
Type A
x1
x2
x0.5
Type B
x0.5
x1
x2
Type B
x2
x0.5
x1


Attaque
Neutre ou Type
Buff / Debuff
Ratio (puissance) de l’attaque
Nombre de charges (par combat)
Chance de coup critique
Buff / Debuff
Modification de stats
Dure jusqu’au changement de créature
