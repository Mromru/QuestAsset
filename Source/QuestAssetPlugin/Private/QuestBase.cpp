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

void UQuestBase::NotifyNodeLeft(UQuestNodeBase* QuestNode, bool Success)
{
	ensure(QuestNode == ActiveNode);
	if(OnNodeLeft.IsBound())
		OnNodeLeft.Broadcast(QuestNode, Success);
}

void UQuestBase::NotifyQuestEnded(UQuestNodeBase* QuestNode, bool Success)
{
	ensure(QuestNode == ActiveNode);
	if(OnQuestEnded.IsBound())
		OnQuestEnded.Broadcast(this, Success);
}

void UQuestBase::ChangeActiveNode(UQuestNodeBase* Node)
{
	ActiveNode = Node;
	Node->ActivateNode();
}

void UQuestBase::RunQuest()
{
	StartQuestFromBeginning();
}
