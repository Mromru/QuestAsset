// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "QuestNode.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class QUESTASSETPLUGIN_API UQuestNode : public UObject
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

protected:
	/*Quest, that this instance of the node is a part of*/
	UPROPERTY()
	UQuest* Quest;
};
