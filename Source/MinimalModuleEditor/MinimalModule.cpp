// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "MinimalModule.h"

IMPLEMENT_GAME_MODULE(FMinimalModuleEditorModule, MinimalModuleEditor);

DEFINE_LOG_CATEGORY(LogMinimalModuleEditor);

#define LOCTEXT_NAMESPACE "FMinimalModuleEditor"

void FMinimalModuleEditorModule::StartupModule()
{
    UE_LOG(LogMinimalModuleEditor, Log, TEXT("MinimalModuleEditorStarted"));
}

void FMinimalModuleEditorModule::ShutdownModule()
{
    UE_LOG(LogMinimalModuleEditor, Log, TEXT("MinimalModuleEditorEnded"));

}

#undef LOCTEXT_NAMESPACE