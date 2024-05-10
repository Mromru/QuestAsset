// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "QuestBase.generated.h"

class UQuestNodeBase;
DECLARE_MULTICAST_DELEGATE_OneParam(FOnNodeActivated, UQuestNodeBase*);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnNodeLeft, UQuestNodeBase*, bool);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnQuestEnded, UQuestBase*, bool)
DECLARE_MULTICAST_DELEGATE(FOnQuestStarted)

/**
 * Quest asset for use with a GraphEditor.
 * Consists of QuestNodes and allows execution of their code.
 */
UCLASS(BlueprintType)
class QUESTASSETPLUGIN_API UQuestBase : public UObject
{
	GENERATED_BODY()

	//We don't want to expose the control logic of the quest to the public api, so we befriend UQuestNode, so it has those privileges
	friend UQuestNodeBase;

#if WITH_EDITORONLY_DATA && 0 //Integration with the editor. Schema should be able to add/modify nodes freely. 
	friend class UQuestEdGraphSchemaBase;
#endif
	
public:
	/* Name of the quest, which appears in the quest journal */
	UPROPERTY(EditDefaultsOnly)
	FText QuestName;

	/* Starts a quest from a root node. */
	UFUNCTION(BlueprintCallable)
	void StartQuestFromBeginning();

	/* Starts a quest from a given node, which could be used to restore a quest state from a save system */
	UFUNCTION(BlueprintCallable)
	void StartQuestFromNode(UQuestNodeBase* Node);

#if WITH_EDITORONLY_DATA
	/* Utility function used to test the quest without launching the game*/
	UFUNCTION(CallInEditor)
	void RunQuest();

	UPROPERTY()
	UEdGraph* EdGraph;
#endif
	
	/* Delegates, could be used for a debugger or a quest journal */
	FOnNodeActivated OnNodeActivated;
	FOnNodeLeft OnNodeLeft;
	FOnQuestStarted OnQuestStarted;
	FOnQuestEnded OnQuestEnded;

protected:
	/* Start node of a quest */
	UPROPERTY()
	UQuestNodeBase* RootNode;

	/* Active node, not saved in the asset */
	UPROPERTY(Transient)
	UQuestNodeBase* ActiveNode;

	/* Called in ActiveNode's Activate method */
	void NotifyNodeActivated(UQuestNodeBase* QuestNode);

	/* Called in ActiveNode's Leave method*/
	void NotifyNodeLeft(UQuestNodeBase* QuestNode, bool Success);

	/* Called when a quest needs to be ended */
	UFUNCTION(BlueprintCallable)
	void NotifyQuestEnded(UQuestNodeBase* QuestNode, bool Success);

	/* Updates ActiveNode to specified Node and Activates it */
	void ChangeActiveNode(UQuestNodeBase* Node);
};
