// Fill out your copyright notice in the Description page of Project Settings.


#include "Quest.h"

#include "QuestNode.h"

void UQuest::StartQuestFromBeginning()
{
	if(OnQuestStarted.IsBound())
		OnQuestStarted.Broadcast();
	StartQuestFromNode(RootNode);
}

void UQuest::StartQuestFromNode(UQuestNode* Node)
{
	ActiveNode = Node;
	ActiveNode->ActivateNode();
}

void UQuest::NotifyNodeActivated(UQuestNode* QuestNode)
{
	ensure(QuestNode == ActiveNode);
	if(OnNodeActivated.IsBound())
		OnNodeActivated.Broadcast(QuestNode);
}

void UQuest::NotifyNodeLeft(UQuestNode* QuestNode)
{
	ensure(QuestNode == ActiveNode);
	if(OnNodeLeft.IsBound())
		OnNodeLeft.Broadcast(QuestNode);
}

void UQuest::FinishQuest(bool Success)
{
	if(OnQuestEnded.IsBound())
		OnQuestEnded.Broadcast(Success);
}

void UQuest::RunQuest()
{
	StartQuestFromBeginning();
}
