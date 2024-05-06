// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestAssetActions.h"

#include "QuestBase.h"

#define LOCTEXT_NAMESPACE
FQuestAssetActions::FQuestAssetActions(const uint32 InAssetCategory)
{
	AssetCategory = InAssetCategory;
}

FText FQuestAssetActions::GetName() const
{
	return INVTEXT("Quest Asset");
}

UClass* FQuestAssetActions::GetSupportedClass() const
{
	return UQuestBase::StaticClass();
}

FColor FQuestAssetActions::GetTypeColor() const
{
	return FColor(0,206,209);
}

uint32 FQuestAssetActions::GetCategories()
{
	return AssetCategory;
}
#undef LOCTEXT_NAMESPACE