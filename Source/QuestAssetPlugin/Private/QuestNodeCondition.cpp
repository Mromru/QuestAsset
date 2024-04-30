// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestNodeCondition.h"


void UQuestNodeCondition::StartupCondition_Implementation()
{
	//Empty in BaseClass
}

void UQuestNodeCondition::ShutdownCondition_Implementation()
{
	//Empty in BaseClass
}

bool UQuestNodeCondition::EvaluateCondition_Implementation()
{
	return false;
}

FDelegateHandle UQuestNodeCondition::RegisterObserver(FOnQuestNodeConditionStateChangedObserver Observer)
{
	return OnQuestNodeConditionStateChanged.Add(Observer);
}

void UQuestNodeCondition::RemoveObserver(FDelegateHandle ObserverHandle)
{
	OnQuestNodeConditionStateChanged.Remove(ObserverHandle);
}
