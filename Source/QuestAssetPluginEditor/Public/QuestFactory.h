// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "QuestFactory.generated.h"

/**
 * 
 */
UCLASS()
class QUESTASSETPLUGINEDITOR_API UQuestFactory : public UFactory
{
	GENERATED_BODY()
public:
	UQuestFactory();

	/* Creates an instance */
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
