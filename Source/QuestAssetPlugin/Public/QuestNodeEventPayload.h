// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "QuestNodeEventPayload.generated.h"

/**
 * A class used to store relevant information used to fire events during the node Activation or Leaving.
 * Can be subclassed to send additional data.
 */
UCLASS(Blueprintable)
class QUESTASSETPLUGIN_API UQuestNodeEventPayload : public UObject
{
	GENERATED_BODY()
public:
	/*The Quest that the calling node is a part of*/
	UPROPERTY(VisibleAnywhere)
	UQuestBase* Quest;

	/*A node calling the event*/
	UPROPERTY(VisibleAnywhere)
	UQuestNodeBase* QuestNode;
};
