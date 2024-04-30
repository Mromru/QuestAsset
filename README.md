# QuestAssetPlugin
 Quest asset for use with a graph editor
 
![Quest Graph](https://github.com/Mromru/QuestAsset/blob/main/Resources/QuestGraphExample.png)

Representing Quest as a graph structure, consisting of smaller tasks (represented by Nodes), that are executed in order.

The different paths that could be taken in such a system are typically influenced by the player's actions.

## Main Components:
- Quest
- QuestNode
- QuestNodeCondition
- QuestNodeEvent

## Quest
A custom asset. Contains the logic of the quest. During the runtime it keeps track of the quest state and notifies external systems about it (for example journal or debugger).
It can be started from the beginning or (for instance when the persistence system is in place) from a given node.

## QuestNode
A base class for Nodes in QuestGraph. It's a group of work that needs to be done at given step of the quest. 
It can be a Player's objective or a task that needs to be done by the system. For example: Objective:PetTheCat or RewardThePlayer.

It has two notable events: Activation and Leaving. Activation being called at the beginning of the execution and latter during the execution end.
During an activation, we should have a logic that tries to reach the Leaving state. Sometimes it's just as simple as calling LeaveNode after our work is done (for example when giving a reward), sometimes we need to wait for the player to do something first.

The node also selects its successor amongst its children. (Which could potentially be leveraged in the future to make composite nodes, such as Sequences, possible)

## QuestNodeCondition (WiP)
In order to influence the paths that the system takes during the execution, we do two things. The first one is prioritization of the children (the one with highest priority will try to execute first) and we also check the conditions on the nodes

## QuestNodeEvent (WiP)
Sometimes, during the execution of the node you want to trigger something, maybe a cutscene, opening a path in the level or something else. Those are designed to be small, reusable actions that are fired at the node activation and when they leave.
