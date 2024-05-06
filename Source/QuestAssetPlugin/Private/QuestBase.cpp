// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestBase.h"

#include "QuestNodeBase.h"

void UQuestBase::StartQuestFromBeginning()
{
	if(OnQuestStarted.IsBound())
		OnQuestStarted.Broadcast();
	StartQuestFromNode(RootNode);
}

void UQuestBase::StartQuestFromNode(UQuestNodeBase* Node)
{
	ActiveNode = Node;
	ActiveNode->ActivateNode();
}

void UQuestBase::NotifyNodeActivated(UQuestNodeBase* QuestNode)
{
	ensure(QuestNode == ActiveNode);
	if(OnNodeActivated.IsBound())
		OnNodeActivated.Broadcast(QuestNode);
}

void UQuestBase::NotifyNodeLeft(UQuestNodeBase* QuestNode)
{
	ensure(QuestNode == ActiveNode);
	if(OnNodeLeft.IsBound())
		OnNodeLeft.Broadcast(QuestNode);
}

void UQuestBase::FinishQuest(bool Success)
{
	if(OnQuestEnded.IsBound())
		OnQuestEnded.Broadcast(Success);
}

void UQuestBase::RunQuest()
{
	StartQuestFromBeginning();
}
