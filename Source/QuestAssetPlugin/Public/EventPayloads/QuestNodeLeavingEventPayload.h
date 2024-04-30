// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestNodeEventPayload.h"
#include "QuestNodeLeavingEventPayload.generated.h"

/**
 * A version of QuestNodeEventPayload that stores the state of the node when leaving for additional context.
 */
UCLASS(Blueprintable)
class QUESTASSETPLUGIN_API UQuestNodeLeavingEventPayload : public UQuestNodeEventPayload
{
	GENERATED_BODY()

public:
	/* The state the node was when leaving */
	UPROPERTY()
	bool Success;
};
