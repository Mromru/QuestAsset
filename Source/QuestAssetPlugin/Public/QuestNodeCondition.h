// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "QuestNodeCondition.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnQuestNodeConditionStateChanged, bool /*NewState*/)
DECLARE_DELEGATE_OneParam(FOnQuestNodeConditionStateChangedObserver, bool /*NewState*/)

/**
 * Conditions allow execution of the node. They are only active when associated is active or waits for a valid successor.
 */
UCLASS(Abstract, Blueprintable)
class QUESTASSETPLUGIN_API UQuestNodeCondition : public UObject
{
	GENERATED_BODY()

public:
	/* Here you bind to the things that you need to observe to update the condition or cache values you need for later evaluation*/
	UFUNCTION(BlueprintNativeEvent)
	void StartupCondition();

	/* Here you can clean up when the Condition is deactivated*/
	UFUNCTION(BlueprintNativeEvent)
	void ShutdownCondition();

	/* Here you evaluate the condition */
	UFUNCTION(BlueprintNativeEvent)
	bool EvaluateCondition();

	/*When you need to wait until condition state changes, you can register an observer here*/
	FDelegateHandle RegisterObserver(FOnQuestNodeConditionStateChangedObserver Observer);

	/*When you no longer need an observer of the condition state, you can remove it here by providing a handle*/
	void RemoveObserver(FDelegateHandle Handle);
	
protected:
	FOnQuestNodeConditionStateChanged OnQuestNodeConditionStateChanged;
};