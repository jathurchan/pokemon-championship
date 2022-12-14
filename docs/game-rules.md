![AEVITUU](https://user-images.githubusercontent.com/91960907/197291599-fd09ea1b-735c-4a98-8dc4-46fc2d96d52f.png)
# Pokémon Championship

![ARBERMY](https://user-images.githubusercontent.com/91960907/197291630-a4b8441e-1b0f-4e3f-8d4e-6b5ee2834b5d.png)

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

> The winner is the player who detains the first place in the ladder.

#### Conditions of ranking 

> Players are ranked based on the points scored at each round. 
> If there is a tie with other players, those are ranked based on their knocked-out/saved ratio.

#### Tournament mode

> At the end of the last round of the Second Leg Encounters, if there are players with the exact same amount of points and knocked-out/saved ratio, a tie-breaker will take place between them to define their final rank.<br/>
> A random tournament tree is generated with Best of One format between the tied players.

#### Team Creation

> Each player has to choose a team of 6 creatures from the catalog. Players would not be able to modify their choices during the championship, except during the mid-season pause.

#### First Leg Encounters

> Each player will encounter other participants once in best of one format matches (for a total of 7 encounters).

#### Mid-Season Pause

> Each player has the possibility to replace* one of their creatures with another one picked from the catalog.
> 
> <br/>* *A player can decide not to replace any of their creatures during this phase and keep the same team for the second leg.*

#### Second Leg Encounters

> Each player will encounter other participants once in best of one format matches (for a total of 7 additional encounters).

#### Tie-breakers + Final Ladder

> Sets of tied players enter in Tournament Mode to resolve potential ties. Once all ties are resolved, final rankings are displayed.

![VEILOW](https://user-images.githubusercontent.com/91960907/197291780-8c4c2b25-b7bb-4d19-bacd-becee3f53d90.png)

### Combat rules

#### Before the beginning of the combat

> Each player will have access to their opponent's creature list and will decide to ban one of them. The banned creature will not be able to participate in this encounter.<br/><br/>
> With the remaining creatures (5), each player will build their team of 3 creatures in blind mode (players do not see in real time their opponent's choices).<br/><br/>
> Within their team of 3, players will be able to (this is not mandatory) set 2 items (see Item section).
> Finally, players choose the first creature to send to the battlefield.

#### During the combat

> Each player chooses an action to perform between 2 possibilities :
> - `Attack`
> - `Substitute the active creature*`
> 
> No matter what they choose, players must confirm their action with the "End Turn" button.<br/>
> Note that only one action can be performed per turn and players' choices are seen from the opposite side after they both confirmed their "End Turn".
>
> <br/>* *Players can substitute their active creature as many times as they want as long as they have another available creature. This action is always performed before any opponent's attack*

##### When a Creature is Knocked-out

> The knocked-out creature's owner chooses which of their remaining creatures enters the battlefield before the next turn begins.<br/>
> If they have no available creatures left, the encounter ends.

##### End of the encounter : Winning condition

> The first player who knocks-out all 3 of their opponent's creatures wins the match.

### Game elements

#### Creatures
> Creatures are the main element of the game. Each creature have a type, a set of 4 attacks and 4 base statistics :
> - `Health (HP)`
> - `Attack (Atk)`
> - `Defense (Def)`
> - `Speed (Spd)`

   ![FLAREZAEL](https://user-images.githubusercontent.com/91960907/197291221-27a829c1-c213-41eb-b1a7-b0de0cf124fb.png)

#### Items
> Items can be given to a creature during the first part of an encounter. There are 2 types of items in the game :
> - `Passive statistic bonuses`
>   - `Raises Attack (Atk)`
>   - `Raises Defense (Def)`
>   - `Raises Speed (Spd)`
> - `Triggered heal`
>   - `Heals the creature if its current Health (HP) is below 50%`
>
> Only one item can be given to a creature and cannot be changed until the end of the encounter.


#### Attacks

> There are 2 types of attacks that can be part of the creatures' attack pool :
> - `Damage dealers`
>   - `Represented by a power value`
> - `Statistic changers*`
>   - `Increases one of its owner's statistic (Buff)`
>   - `Decreases one of its opponent's statistic (Debuff)`
> 
> Every attack has also a limited amount of uses per encounter which is represented by its "Charges" attribute.
> This attribute decreases by 1 at every use until it reaches 0. If that happens, the attack is no longer available until the end of the encounter.
> 
> * *Those changes last as long as the creature is active on the battlefield. If the creature is substituted, the creature's statistics are set to their initial value* 
> 
