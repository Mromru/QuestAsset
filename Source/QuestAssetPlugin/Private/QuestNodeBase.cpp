// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestNodeBase.h"

#include "QuestBase.h"
#include "QuestNodeConditionBase.h"
#include "QuestNodeEventBase.h"
#include "QuestNodeEventPayload.h"
#include "EventPayloads/QuestNodeLeavingEventPayload.h"

void UQuestNodeBase::ActivateNode_Implementation()
{
	Quest->NotifyNodeActivated(this);

	const UQuestNodeEventPayload* Context = GetNodeActivatedEventContext();
	for(auto& Event : NodeActivatedEvents)
	{
		Event->ActivateEvent(Context);
	}
}

void UQuestNodeBase::LeaveNode_Implementation(bool Success)
{
	const UQuestNodeEventPayload* Context = GetNodeLeavingEventContext(Success);
	if(Success)
	{
		for(auto& Event : NodeSucceededEvents)
		{
			Event->ActivateEvent(Context);
		}
	}
	else
	{
		for(auto& Event : NodeFailedEvents)
		{
			Event->ActivateEvent(Context);
		}
	}
	Quest->NotifyNodeLeft(this);
}

bool UQuestNodeBase::CanActivateNode()
{
	return ActivationCondition->EvaluateCondition();
}

UQuestNodeEventPayload* UQuestNodeBase::GetNodeActivatedEventContext()
{
	auto Context = NewObject<UQuestNodeEventPayload>();
	Context->Quest = Quest;
	Context->QuestNode = this;
	return Context;
}

UQuestNodeEventPayload* UQuestNodeBase::GetNodeLeavingEventContext(bool Success)
{
	auto Context = NewObject<UQuestNodeLeavingEventPayload>();
	Context->Quest = Quest;
	Context->QuestNode = this;
	Context->Success = Success;
	return Context;
}

