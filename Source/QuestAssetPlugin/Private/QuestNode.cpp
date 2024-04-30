// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestNode.h"

#include "Quest.h"
#include "QuestNodeCondition.h"
#include "QuestNodeEvent.h"
#include "QuestNodeEventPayload.h"
#include "EventPayloads/QuestNodeLeavingEventPayload.h"

void UQuestNode::ActivateNode_Implementation()
{
	Quest->NotifyNodeActivated(this);

	const UQuestNodeEventPayload* Context = GetNodeActivatedEventContext();
	for(auto& Event : NodeActivatedEvents)
	{
		Event->ActivateEvent(Context);
	}
}

void UQuestNode::LeaveNode_Implementation(bool Success)
{
	const UQuestNodeEventPayload* Context = GetNodeLeavingEventContext(Success);
	if(Success)
	{
		for(auto& Event : NodeLeavingSuccessfullyEvents)
		{
			Event->ActivateEvent(Context);
		}
	}
	else
	{
		for(auto& Event : NodeLeavingFailedEvents)
		{
			Event->ActivateEvent(Context);
		}
	}
	Quest->NotifyNodeLeft(this);
}

bool UQuestNode::CanActivateNode()
{
	return ActivationCondition->EvaluateCondition();
}

UQuestNodeEventPayload* UQuestNode::GetNodeActivatedEventContext()
{
	auto Context = NewObject<UQuestNodeEventPayload>();
	Context->Quest = Quest;
	Context->QuestNode = this;
	return Context;
}

UQuestNodeEventPayload* UQuestNode::GetNodeLeavingEventContext(bool Success)
{
	auto Context = NewObject<UQuestNodeLeavingEventPayload>();
	Context->Quest = Quest;
	Context->QuestNode = this;
	Context->Success = Success;
	return Context;
}

