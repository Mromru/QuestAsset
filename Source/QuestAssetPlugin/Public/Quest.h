// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Quest.generated.h"

class UQuestNode;
DECLARE_MULTICAST_DELEGATE_OneParam(FOnNodeActivated, UQuestNode*);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnNodeLeft, UQuestNode*);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnQuestEnded, bool)
DECLARE_MULTICAST_DELEGATE(FOnQuestStarted)

/**
 * Quest asset for use with a GraphEditor.
 * Consists of QuestNodes and allows execution of their code.
 */
UCLASS(BlueprintType)
class QUESTASSETPLUGIN_API UQuest : public UObject
{
	GENERATED_BODY()

	//We don't want to expose the control logic of the quest to the public api, so we befriend UQuestNode, so it has those privileges
	friend UQuestNode;
	
public:
	/* Name of the quest, which appears in the quest journal */
	UPROPERTY(EditDefaultsOnly)
	FText QuestName;

	UFUNCTION(BlueprintCallable)
	void StartQuestFromBeginning();

	/* Starts a quest from a given node, which could be used to restore a quest state from a save system */
	UFUNCTION(BlueprintCallable)
	void StartQuestFromNode(UQuestNode* Node);

	UFUNCTION(BlueprintCallable)
	void FinishQuest(bool Success);

#if WITH_EDITORONLY_DATA
	/* Utility function used to test the quest without launching the game*/
	UFUNCTION(CallInEditor)
	void RunQuest();
#endif
	
	/* Delegates, could be used for a debugger or a quest journal */
	FOnNodeActivated OnNodeActivated;
	FOnNodeLeft OnNodeLeft;
	FOnQuestStarted OnQuestStarted;
	FOnQuestEnded OnQuestEnded;

protected:
	/* Start node of a quest */
	UPROPERTY()
	UQuestNode* RootNode;

	/* Active node, not saved in the asset */
	UPROPERTY(Transient)
	UQuestNode* ActiveNode;

	/* Called in ActiveNode's Activate method */
	void NotifyNodeActivated(UQuestNode* QuestNode);

	/* Called in ActiveNode's Leave method*/
	void NotifyNodeLeft(UQuestNode* QuestNode);
};
