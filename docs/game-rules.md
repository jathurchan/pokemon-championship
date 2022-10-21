# Pokémon Championship

## Archetype

> Turn-based Duels (Pokémon-like) following a championship system (+ tournament for tie-brakes)

## Game Rules

### Championship rules

> The championship is composed of 8 players that will face each other twice (two-legged matches) for a total of 14 encounters each. 
> The championship will include 5 phases :
> - `Team Creation`
> - `First Leg Encounters`
> - `Mid-Season Pause`
> - `Second Leg Encounters`
> - `Final Leaderboard`

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

### Team Creation

> Each player has to choose a team of 6 creatures from the catalog. Note that, players would not be able to modify their choices during the championship, apart from during the mid-season pause.

### Mid-Season Pause

> Each player has the possibility to replace one of his creatures choose a team of 6 creatures from the catalog. Note that, players would not be able to modify their choices during the championship, apart from during the mid-season pause.

### First Leg Encounters

> Each player will encounter other participants once in best of one format matches (for a total of 7 encounters).

### Second Leg Encounters

> Each player will encounter other participants once in best of one format matches (for a total of 7 encounters).

Chaque joueur joue 2 fois contre tous les autres (phase aller, phase retour).
Une victoire rapporte 1 point et une défaite 0 point.
On comptabilise le nombre de créatures éliminées et perdues lors de chaque match.
En cas d’égalité du nombre de points à la fin du championnat, la différence entre le nombre de créatures éliminées et perdues détermine le vainqueur.
S’il reste des égalités, un tournoi entre les joueurs est organisé pour déterminer le vainqueur.
Combat
Avant
Chaque joueur banni une des 6 créatures de l’adversaire
Avec les choix restants (parmi les 5), chaque joueur en choisit 3
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
