// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestNodeConditionBase.h"


void UQuestNodeConditionBase::StartupCondition_Implementation()
{
	//Empty in BaseClass
}

void UQuestNodeConditionBase::ShutdownCondition_Implementation()
{
	//Empty in BaseClass
}

bool UQuestNodeConditionBase::EvaluateCondition_Implementation()
{
	return false;
}

FDelegateHandle UQuestNodeConditionBase::RegisterObserver(FOnQuestNodeConditionStateChangedObserver Observer)
{
	return OnQuestNodeConditionStateChanged.Add(Observer);
}

void UQuestNodeConditionBase::RemoveObserver(FDelegateHandle ObserverHandle)
{
	OnQuestNodeConditionStateChanged.Remove(ObserverHandle);
}
