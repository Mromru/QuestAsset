// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestFactory.h"

#include "Quest.h"

UQuestFactory::UQuestFactory()
{
    SupportedClass = UQuest::StaticClass();
    bCreateNew = true;
}

UObject* UQuestFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
    UObject* Context, FFeedbackContext* Warn)
{
    return NewObject<UQuest>(InParent, UQuest::StaticClass(), InName, Flags, Context);
}
