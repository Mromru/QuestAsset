// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestNodeEventPayload.h"
#include "UObject/Object.h"
#include "QuestNodeEventBase.generated.h"

/**
 * 
 */
UCLASS()
class QUESTASSETPLUGIN_API UQuestNodeEventBase : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent)
	void ActivateEvent(const UQuestNodeEventPayload* QuestEventContext);
};
