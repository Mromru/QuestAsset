// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestFactory.h"

#include "QuestBase.h"

UQuestFactory::UQuestFactory()
{
    SupportedClass = UQuestBase::StaticClass();
    bCreateNew = true;
}

UObject* UQuestFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
    UObject* Context, FFeedbackContext* Warn)
{
    return NewObject<UQuestBase>(InParent, UQuestBase::StaticClass(), InName, Flags, Context);
}
