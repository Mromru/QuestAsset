// Copyright Epic Games, Inc. All Rights Reserved.

#include "QuestAssetPluginEditor.h"

#include "AssetToolsModule.h"
#include "IAssetTools.h"
#include "QuestAssetActions.h"

#define LOCTEXT_NAMESPACE "FQuestAssetPluginEditorModule"

void FQuestAssetPluginEditorModule::StartupModule()
{
	//Load AssetToolsModule and register a custom category for the quest assets
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	const uint32 QuestAssetCategory = AssetTools.RegisterAdvancedAssetCategory(
		FName(TEXT("QuestAssetCategory")),
		LOCTEXT("QuestAssetPluginCategory", "Quests"));

	//Register AssetTypeActions of a Quest to allow its creation
	QuestAssetTypeActions = MakeShareable(new FQuestAssetActions(QuestAssetCategory));
	AssetTools.RegisterAssetTypeActions(QuestAssetTypeActions.ToSharedRef());
}

void FQuestAssetPluginEditorModule::ShutdownModule()
{
	//Cleanup
	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		FAssetToolsModule::GetModule().Get().UnregisterAssetTypeActions(QuestAssetTypeActions.ToSharedRef());
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FQuestAssetPluginEditorModule, QuestAssetPlugin)