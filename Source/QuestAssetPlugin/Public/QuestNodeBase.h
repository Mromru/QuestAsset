// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "QuestNodeBase.generated.h"

class UQuestNodeConditionBase;
class UQuestNodeEventBase;
class UQuestNodeEventPayload;
/**
 * Quest node. A unit of work in a Quest.
 */
UCLASS(Blueprintable)
class QUESTASSETPLUGIN_API UQuestNodeBase : public UObject
{
	GENERATED_BODY()
public:
	/* Called at the beginning of execution of the node.
	 * Responsible for logic of how to get to the LeaveNode() and with what effect (success/failure)
	 * Fires OnNodeActivatedEvents
	 */
	UFUNCTION(BlueprintNativeEvent)
	void ActivateNode();

	/* Called at the end of execution of the node, potentially for some cleanup. Notifies a quest that we leave the node*/
	UFUNCTION(BlueprintNativeEvent)
	void LeaveNode(bool Success);

	virtual bool CanActivateNode();

	/* You might want to override this method fully in the subclasses. Returns UQuestNodeEventPayload object used when calling NodeActivatedEvents */
	virtual UQuestNodeEventPayload* GetNodeActivatedEventContext();

	/* You might want to override this method fully in the subclasses. Returns UQuestNodeEventPayload object used when calling NodeLeavingEvents */
	virtual UQuestNodeEventPayload* GetNodeLeavingEventContext(bool Success);

	/* Needs to be met before node Activation. For more complicated conditions it can be composed of AND_Conditions and OR_Conditions */ //TODO add CompositeConditions
	UPROPERTY(EditDefaultsOnly)
	UQuestNodeConditionBase* ActivationCondition;
	
	/* Events that are activated when node is Activating */
	UPROPERTY(EditDefaultsOnly)
	TArray<UQuestNodeEventBase*> NodeActivatedEvents;

	/* Events that are activated when node is Leaving with a success state */
	UPROPERTY(EditDefaultsOnly)
	TArray<UQuestNodeEventBase*> NodeSucceededEvents;

	/* Events that are activated when node is leaving with a failed state */
	UPROPERTY(EditDefaultsOnly)
	TArray<UQuestNodeEventBase*> NodeFailedEvents;

	/* Parents - Nodes that directly lead to the node */
	TArray<UQuestNodeBase> Parents;
	
	/* Children - Paths that can be taken after the execution of the node ends
	 * First nodes in collection having highest priority.
	 * This needs to be sorted externally by an asset editor.
	 */
	TArray<UQuestNodeBase> PrioritizedChildren;
	
protected:
	/*Quest, that this instance of the node is a part of*/
	UPROPERTY()
	UQuestBase* Quest;
};