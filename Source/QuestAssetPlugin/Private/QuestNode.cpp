// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestNode.h"

#include "Quest.h"

void UQuestNode::ActivateNode_Implementation()
{
	Quest->NotifyNodeActivated(this);
	//TODO Fire OnNodeActivatedEvents
}

void UQuestNode::LeaveNode_Implementation(bool Success)
{
	Quest->NotifyNodeLeft(this);
}
