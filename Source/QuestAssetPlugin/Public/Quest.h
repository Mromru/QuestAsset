// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Quest.generated.h"

/**
 * Quest asset for use with a GraphEditor.
 * Consists of QuestNodes and allows execution of their code.
 */
UCLASS()
class QUESTASSETPLUGIN_API UQuest : public UObject
{
	GENERATED_BODY()

	/* Name of the quest, which appears in the quest journal */
	UPROPERTY(EditDefaultsOnly)
	FText QuestName;
};
