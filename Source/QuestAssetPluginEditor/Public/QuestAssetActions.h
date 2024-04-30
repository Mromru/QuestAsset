// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"

/**
 * AssetTypeActions of the UQuest class.
 * Asset type actions can be registered in the module to allow creation of the assets. 
 */
class QUESTASSETPLUGINEDITOR_API FQuestAssetActions : public FAssetTypeActions_Base
{
public:
	explicit FQuestAssetActions(const uint32 InAssetCategory);

	/* Returns a name of the asset class that appears in the context browser when mouse overed */
	virtual FText GetName() const override;

	/* Specifies an asset class we are associated with */
	virtual UClass* GetSupportedClass() const override;

	/* Specifies a color of asset icon in a content browser */
	virtual FColor GetTypeColor() const override;

	/* Returns a category Id, which our asset appears in during its creation */
	virtual uint32 GetCategories() override;

protected:
	/* Id of a category, should be assigned by our module*/
	uint32 AssetCategory;
};
